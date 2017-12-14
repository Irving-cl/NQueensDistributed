
#include <iostream>
#include <functional>

#include <boost/asio.hpp>

class master
{
};

class session
{
public:

    session(boost::asio::io_service& ios)
      : socket_(ios)
    {
    }

    void start(boost::asio::ip::address& address, uint16_t port)
    {
        socket_.async_connect(boost::asio::ip::tcp::endpoint(address, port),
            std::bind(&session::connect_handler, this, std::placeholders::_1));
    }

private:

    enum { kMaxLength = 65536 };

    boost::asio::ip::tcp::socket socket_;
    char buf_[kMaxLength];

    void connect_handler(boost::system::error_code ec)
    {
        socket_.async_read_some(boost::asio::buffer(buf_, kMaxLength),
            std::bind(&session::read_handler, this, std::placeholders::_1, std::placeholders::_2));
    }

    void read_handler(boost::system::error_code ec, size_t len)
    {
        /// Parse the packet, find corresponding protocol

        /*
         * Protocols:
         * 1. SLAVE_ASK_FOR_WORK_REQ
         * 2. SLAVE_GIVE_RESULT
         */
    }
};


int main()
{
    /// 1. read configuration file
    
    /// 2. connect all the slaves
    boost::asio::io_service ios;

    ios.run();
}

