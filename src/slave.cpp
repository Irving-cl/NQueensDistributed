
#include <sys/sysinfo.h>

#include <iomanip>
#include <iostream>
#include <functional>
#include <memory>
#include <mutex>
#include <thread>

#include <boost/asio.hpp>
#include "nqueens_solver.h"
#include "proto/nqueens.pb.h"
#include "work_manager.h"

static int core_count = 1;
static int64_t ans = 0;

std::mutex mtx;

std::shared_ptr<Work> get_work_locked(WorkManager& work_manager)
{
    std::lock_guard<std::mutex> lock(mtx);
    return work_manager.get_work();
}

void bar(int id, WorkManager& work_manager)
{
    //struct timeval tpstart, tpend;
    //gettimeofday(&tpstart, NULL);

    while (true)
    {
        auto work_ptr = get_work_locked(work_manager);
        if (!work_ptr)
        {
            break;
        }
        else
        {
            int64_t tmp = work_ptr->solve();
            std::lock_guard<std::mutex> lock(mtx);
            ans += tmp;
        }
    }

    //gettimeofday(&tpend, NULL);
    //double timeuse = tpend.tv_sec - tpstart.tv_sec + (tpend.tv_usec - tpstart.tv_usec) * 1e-6;
    //std::lock_guard<std::mutex> lock(mtx);
    //std::cout << "Thread[" << id << "]  " << std::setprecision(4) << timeuse << "s\n";
}

int64_t solve(nqueens::MasterAssignWork& master_assign_work)
{
    WorkManager work_manager(master_assign_work.n(), 11);
    std::vector<int> constraint;
    for (int i = 0; i < master_assign_work.constraint_size(); i++)
    {
        constraint.push_back(master_assign_work.constraint(i));
    }
    work_manager.set_constraint(constraint);

    ans = 0;
    std::vector<std::thread> thrds;
    for (int i = 0; i < core_count; i++)
    {
        thrds.push_back(std::thread(bar, i, std::ref(work_manager)));
    }
    for (int i = 0; i < core_count; i++)
    {
        thrds[i].join();
    }
    return ans;
}

class Session
{
public:
    Session(boost::asio::io_service& ios, uint16_t port)
      : acceptor_(ios, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
        socket_(ios)
    {
        do_accept();
    }

private:

    enum { kHeaderLength = 8, kMaxBodyLength = 512 };

    static const char* kPassword;

    boost::asio::ip::tcp::acceptor acceptor_;
    boost::asio::ip::tcp::socket socket_;

    char header_[kHeaderLength];
    char data_[kMaxBodyLength];

    void do_accept()
    {
        acceptor_.async_accept(socket_,
            [this](boost::system::error_code ec)
            {
                ask_for_work();
            });
    }

    void ask_for_work()
    {
        /// Send SLAVE_ASK_FOR_WORK_REQ
        nqueens::SlaveAskForWork slave_ask_for_work;
        slave_ask_for_work.set_password(kPassword);

        int32_t send_length = fill_send_packet(slave_ask_for_work, nqueens::SlaveMsgID::SLAVE_MSG_ASK_FOR_WORK);

        boost::asio::async_write(socket_, boost::asio::buffer(data_, send_length),
            [this](boost::system::error_code ec, std::size_t bytes_transferred)
            {
                do_read_header();
            });
    }

    void send_back_result(int64_t result)
    {
        /// Send SLAVE_MSG_TASK_RESULT
        nqueens::SlaveTaskResult slave_task_result;
        slave_task_result.set_result(result);
        
        int32_t send_length = fill_send_packet(slave_task_result, nqueens::SlaveMsgID::SLAVE_MSG_TASK_RESULT);

        boost::asio::async_write(socket_, boost::asio::buffer(data_, send_length),
            [this](boost::system::error_code ec, std::size_t bytes_transferred)
            {
                ask_for_work();
            });
    }

    void do_read_header()
    {
        boost::asio::async_read(socket_, boost::asio::buffer(header_, kHeaderLength),
            [this](boost::system::error_code ec, std::size_t length)
            {
                if (!ec && length == kHeaderLength)
                {
                    /// Get message id and body length
                    int32_t msg_id = 0;
                    int32_t body_length = 0;
                    memcpy(&msg_id, header_, sizeof(int32_t));
                    memcpy(&body_length, header_ + 4, sizeof(int32_t));

                    /// Read body
                    if (body_length <= kMaxBodyLength)
                    {
                        do_read_body(msg_id, body_length);
                    }
                }
            });
    }

    void do_read_body(int32_t msg_id, int32_t body_length)
    {
        boost::asio::async_read(socket_, boost::asio::buffer(data_, body_length),
            [this, msg_id, body_length](boost::system::error_code ec, std::size_t length)
            {
                if (!ec)
                {
                    if (msg_id == nqueens::MasterMsgID::MASTER_MSG_ASSIGN_WORK)
                    {
                        master_msg_assign_work_callback(body_length);
                    }
                    else
                    {
                        std::cerr << "Get wrong msg id: " << msg_id << "\n";
                    }
                }
            });
    }

    template<typename T>
    int32_t fill_send_packet(T& protobuf, int32_t msg_id)
    {
        std::string serialized_data;
        protobuf.SerializeToString(&serialized_data);
        int32_t body_length = serialized_data.size();

        memcpy(data_, &msg_id, sizeof(int32_t));
        memcpy(data_ + 4, &body_length, sizeof(int32_t));
        memcpy(data_ + 8, serialized_data.c_str(), body_length);

        return kHeaderLength + body_length;
    }

    void master_msg_assign_work_callback(int body_length)
    {
        nqueens::MasterAssignWork master_assign_work;
        std::string body(data_, body_length);
        if (master_assign_work.ParseFromString(body))
        {
            if (!master_assign_work.error_code())
            {
                /// Complete the work
                int64_t result = solve(master_assign_work);

                /// Send back the result and ask for another work
                send_back_result(result);
            }
        }
        else
        {
            std::cerr << "Error protobuf parse from string\n";
        }
    }
};

const char* Session::kPassword = "irving-cl";

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: nqueens_slave <port>\n";
        return -1;
    }

    core_count = get_nprocs() / 2;
    std::cout << "core count: " << core_count << "\n";

    boost::asio::io_service ios;

    int16_t port = ::atoi(argv[1]);
    Session s(ios, port);

    ios.run();
}
