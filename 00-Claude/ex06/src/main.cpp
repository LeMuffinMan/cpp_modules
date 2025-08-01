#include "ConfigParser.hpp"
#include "Setting.hpp"

int main(void)
{
    ConfigParser config("config.txt");
    if (config.load())
    {
        // std::string host = config.getString("db_host");
        // int port = config.getInt("db_port");
        // bool debug = config.getBool("debug_mode");
        // double timeout = config.getDouble("timeout");
    }
    return 0;
}
