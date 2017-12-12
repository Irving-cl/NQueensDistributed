
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

    boost::asio::ip::tcp::acceptor acceptor_;
    boost::asio::ip::tcp::socket socket_;

    void do_accept()
    {
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
