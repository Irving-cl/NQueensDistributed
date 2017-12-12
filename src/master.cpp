
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
    boost::asio::ip::tcp::socket socket_;

    void connect_handler(boost::system::error_code ec)
    {
    }

    void read_handler(boost::system::error_code ec, size_t len)
    {
    }
};


int main()
{
    /// 1. read configuration file
    
    /// 2. connect all the slaves
    boost::asio::io_service ios;

    ios.run();
}

