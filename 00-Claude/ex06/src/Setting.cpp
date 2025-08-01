#include "Setting.hpp"
#include <iostream>

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

