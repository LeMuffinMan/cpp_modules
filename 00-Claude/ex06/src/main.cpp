#include "ConfigParser.hpp"
#include "Setting.hpp"
#include <iostream>

int main(void)
{
    ConfigParser config("config.txt");
    if (config.load())
    {
        std::string host = config.getString("db_host");
        int port = config.getInt("db_port");
        std::cout << "port = " << port << std::endl;
        bool debug = config.getBool("debug_mode");
        std::cout << "debug = " << debug << std::endl;
        double timeout = config.getDouble("timeout");
        std::cout << "timeout = " << timeout << std::endl;
    }
    return 0;
}
