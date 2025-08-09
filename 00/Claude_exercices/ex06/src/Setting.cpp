#include "Setting.hpp"
#include <iostream>
#include <sstream>
#include <cctype>

Setting::Setting() : _key(""), _value("")
{
    // std::cout << "Setting default constructor called" << std::endl;
}

Setting::Setting(std::string key, std::string value)
    : _key(key), _value(value)
{
    std::cout << "Setting created: " << _key << "=" << _value << std::endl;
}

Setting::Setting(const Setting& other)
    : _key(other._key), _value(other._value)
{
    // std::cout << "Setting Copy constructor called" << std::endl;
}


Setting& Setting::operator=(const Setting& other)
{
    // std::cout << "Setting Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _key = other._key;
        _value = other._value;
    }
    return *this;
}

Setting::~Setting()
{
    // std::cout << "Setting Destructor called" << std::endl;
}

std::string Setting::asString()
{
    return _value;
}

int Setting::asInt()
{
    std::istringstream iss(_value);
    int val;
    char c;

    if (!(iss >> val))
        throw std::runtime_error("Invalid int for key '" + _key + "': " + _value);

    if (iss >> c)
        throw std::runtime_error("Invalid int (extra characters) for key '" + _key + "': " + _value);

    return val;
}


double Setting::asDouble()
{
    std::istringstream iss(_value);
    double val;
    char c;

    if (!(iss >> val))
        throw std::runtime_error("Invalid double for key '" + _key + "': " + _value);

    if (iss >> c)
        throw std::runtime_error("Invalid double (extra characters) for key '" + _key + "': " + _value);

    return val;
}


bool Setting::asBool()
{
    std::string val = _value;

    for (size_t i = 0; i < val.size(); ++i)
    {
        val[i] = std::tolower(static_cast<unsigned char>(val[i]));
    }
    if (val == "true" || val == "1") return true;
    if (val == "false" || val == "0") return false;
    throw std::runtime_error("Invalid bool for key '" + _key + "': " + _value);
}
