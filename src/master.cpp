
#include <iomanip>
#include <iostream>
#include <fstream>
#include <functional>
#include <memory>
#include <mutex>
#include <string.h>

#include <boost/asio.hpp>
#include "nqueens_solver.h"
#include "proto/nqueens.pb.h"
#include "work_manager.h"

class Master
{
public:

    Master(int n, int degree)
      : work_manager_(n, degree),
        result_(0),
        n_(n)
    {

    }

    std::shared_ptr<Work> get_work()
    {
        return work_manager_.get_work();
    }

    void add_result(int64_t count)
    {
        result_ += count;
    }

    int32_t get_n()
    {
        return n_;
    }

    int64_t get_result()
    {
        return result_;
    }
    
private:

    WorkManager work_manager_;

    std::mutex mtx_;

    int32_t n_;
    int64_t result_;
};

class Session
  : public std::enable_shared_from_this<Session>
{
public:

    Session(boost::asio::io_service& ios, Master& master)
      : socket_(ios),
        master_(master)
    {

    }

    void start(boost::asio::ip::address address, uint16_t port)
    {
        auto self(shared_from_this());
        socket_.async_connect(boost::asio::ip::tcp::endpoint(address, port),
            [this, self](boost::system::error_code ec)
            {
                if (!ec)
                {
                    do_read_header();
                }
            });
    }

private:

    enum { kMaxBodyLength = 512, kHeaderLength = 8 };

    static const char* kPassword;

    boost::asio::ip::tcp::socket socket_;
    Master& master_;
    char header_[kHeaderLength];
    char data_[kMaxBodyLength];

    void do_read_header()
    {
        auto self(shared_from_this());
        boost::asio::async_read(socket_, boost::asio::buffer(header_, kHeaderLength),
            [this, self](boost::system::error_code ec, std::size_t length)
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
        auto self(shared_from_this());
        boost::asio::async_read(socket_, boost::asio::buffer(data_, body_length),
            [this, self, msg_id, body_length](boost::system::error_code ec, std::size_t length)
            {
                if (!ec)
                {
                    if (msg_id == nqueens::SlaveMsgID::SLAVE_MSG_ASK_FOR_WORK)
                    {
                        slave_msg_ask_for_work_callback();
                    }
                    else if (msg_id == nqueens::SlaveMsgID::SLAVE_MSG_TASK_RESULT)
                    {
                        slave_msg_task_result_callback(body_length);
                    }
                    else
                    {
                        std::cerr << "Get wrong msg id: " << msg_id << "\n";
                    }
                    
                    do_read_header();
                }
            });
    }

    void slave_msg_ask_for_work_callback()
    {
        auto self(shared_from_this());

        /// Run master and send a MASTER_MSG_ASSIGN_WORK to the slave
        auto work_ptr = master_.get_work();
        nqueens::MasterAssignWork master_assign_work;
        if (work_ptr)
        {
            master_assign_work.set_error_code(nqueens::ErrorCode::ERROR_NO_ERROR);
            master_assign_work.set_n(master_.get_n());
            std::vector<int32_t> constraint = work_ptr->get_constraint();
            for (int32_t ele : constraint)
            {
                master_assign_work.add_constraint(ele);
            }
        }
        else
        {
            master_assign_work.set_error_code(nqueens::ErrorCode::ERROR_MASTER_NO_MORE_WORK);
        }

        /// Fill head and body
        std::string serialized_data;
        master_assign_work.SerializeToString(&serialized_data); 
        int32_t body_length = serialized_data.size();
        int32_t msg_id = nqueens::MasterMsgID::MASTER_MSG_ASSIGN_WORK;
        memcpy(data_, &msg_id, sizeof(int32_t));
        memcpy(data_ + 4, &body_length, sizeof(int32_t));
        memcpy(data_ + 8, serialized_data.c_str(), body_length);

        /// Do read header agian when async_send succeed
        boost::asio::async_write(socket_, boost::asio::buffer(data_, kHeaderLength + body_length),
            [this, self](boost::system::error_code ec, std::size_t bytes_transferred)
            {
                if (!ec)
                {
                    
                }
            });
    }

    void slave_msg_task_result_callback(int body_length)
    {
        std::string body(data_, body_length);
        nqueens::SlaveTaskResult slave_task_result;
        if (slave_task_result.ParseFromString(body))
        {
            master_.add_result(slave_task_result.result());
        }
    }
};

const char* Session::kPassword = "irving-cl";

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: master <n>\n";
        return -1;
    }
    int n = ::atoi(argv[1]);

    /// 1. read configuration file
    std::fstream fs("slaves.conf", std::fstream::in);
    int32_t n_slaves = 0;
    fs >> n_slaves;
    std::cout << "slaves: " << n_slaves << "\n";

    /// 2. connect all the slaves
    boost::asio::io_service ios;
    Master master(n, 13);

    struct timeval tpstart, tpend;
    gettimeofday(&tpstart, NULL);

    std::string ip;
    int16_t port;
    for (int i = 0; i < n_slaves; i++)
    {
        fs >> ip >> port;
        std::cout << "ip:" << ip << "   port:" << port << "\n";
        std::make_shared<Session>(ios, master)->start(
            boost::asio::ip::address::from_string(ip.c_str()), port);
    }

    ios.run();

    std::cout << "Result:" << master.get_result() << "\n";

    gettimeofday(&tpend, NULL);
    double timeuse = tpend.tv_sec - tpstart.tv_sec + (tpend.tv_usec - tpstart.tv_usec) * 1e-6;
    std::cout << "Time:" << std::setprecision(4) << timeuse << "s\n";
}

