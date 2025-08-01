#ifndef CONFIGPARSER_HPP
#define CONFIGPARSER_HPP

#include <string>
#include <map>
#include "Setting.hpp"

class ConfigParser
{
public:
    ConfigParser(std::string file); // Default constructor
    ConfigParser(const ConfigParser& other); // Copy constructor
    ConfigParser& operator=(const ConfigParser& other); // Copy assignment
    ~ConfigParser(); // Destructor
    int load();
    std::string getString(std::string key);
    int getInt(std::string key);
    bool getBool(std::string key);
    double getDouble(std::string key);
private:
    std::map<std::string, Setting> _settings;
    std::string _file;
};

#endif
