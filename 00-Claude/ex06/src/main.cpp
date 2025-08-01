#include "ConfigParser.hpp"
#include "Setting.hpp"
#include <iostream>

int main(void)
{
    ConfigParser config("config.txt");
    if (config.load())
    {
        try
        {
            std::string host = config.getString("db_host");
            int port = config.getInt("db_port");
            bool debug = config.getBool("debug_mode");
            double timeout = config.getDouble("timeout");

            std::cout << "Host: " << host << std::endl;
            std::cout << "Port: " << port << std::endl;
            std::cout << "Debug: " << (debug ? "true" : "false") << std::endl;
            std::cout << "Timeout: " << timeout << std::endl;
            std::cout << "Host as int: " << config.getInt("db_host") << std::endl;

        }
        catch (const std::exception& e)
        {
            std::cerr << "Erreur: " << e.what() << std::endl;
        }
    return 0;
    }
}
