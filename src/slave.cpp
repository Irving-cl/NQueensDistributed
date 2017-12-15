
#include <sys/sysinfo.h>

#include <iostream>
#include <functional>

#include <boost/asio.hpp>
#include "proto/nqueens.pb.h"

class Slave
{
};

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
        std::string serialized_data;
        slave_ask_for_work.SerializeToString(&serialized_data);
        
        fill_send_packet(nqueens::SlaveMsgID::SLAVE_MSG_ASK_FOR_WORK, serialized_data.size(), serialized_data);

        boost::asio::async_write(socket_, boost::asio::buffer(data_, kHeaderLength + serialized_data.size()),
            [this](boost::system::error_code ec, std::size_t bytes_transferred)
            {
                do_read_header();
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

    void fill_send_packet(int32_t msg_id, int32_t body_length, const std::string& body)
    {
        memcpy(data_, &msg_id, sizeof(int32_t));
        memcpy(data_ + 4, &body_length, sizeof(int32_t));
        memcpy(data_ + 8, body.c_str(), body_length);
    }

    void master_msg_assign_work_callback(int body_length)
    {
        nqueens::MasterAssignWork master_assign_work;
        std::string body(data_, body_length);
        if (master_assign_work.ParseFromString(body))
        {
            if (!master_assign_work.error_code())
            {
                int32_t constraint_length = master_assign_work.constraint_size();
/*
                std::cout << "Get a work:  " << "constraint_length:" << constraint_length << "   ";
                for (int i = 0; i < constraint_length; i++)
                    std::cout << master_assign_work.constraint(i) << " ";
                std::cout << "\n";
                for (int i = 0; i < 10000000; i++) {} // Waste time
*/                
                ask_for_work();
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

    int core_count = get_nprocs();
    std::cout << "core count: " << core_count << "\n";

    boost::asio::io_service ios;

    int16_t port = ::atoi(argv[1]);
    Session s(ios, port);

    ios.run();
}
