
#include <sys/sysinfo.h>

#include <iostream>
#include <functional>

#include <boost/asio.hpp>

class slave
{
};

class session
{
public:
    session(boost::asio::io_service& ios, uint16_t port)
      : acceptor_(ios, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
        socket_(ios)
    {
        do_accept();
    }

private:

    enum { kMaxLength = 65536 };

    boost::asio::ip::tcp::acceptor acceptor_;
    boost::asio::ip::tcp::socket socket_;

    char buf_[kMaxLength];

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
        async_write(socket_, boost::asio::buffer(buf_, kMaxLength),
            [this](boost::system::error_code ec, std::size_t bytes_transferred)
            {
                socket_.async_read_some(boost::asio::buffer(buf_, kMaxLength),
                    std::bind(&session::read_handler, this, std::placeholders::_1, std::placeholders::_2));
            });
    }

    void read_handler(boost::system::error_code ec, size_t len)
    {
        /// Parse the packet, find corresponding protocol

        /*
         * Protocols:
         * 1. MASTER_ASK_FOR_WORK_RSP
         */
    }
};

int main()
{
    int core_count = get_nprocs();
    std::cout << "core count: " << core_count << "\n";

    boost::asio::io_service ios;

    session s(ios, 10086);

    ios.run();
}
