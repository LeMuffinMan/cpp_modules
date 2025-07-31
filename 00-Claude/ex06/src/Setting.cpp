#include "Setting.hpp"
#include <iostream>

Setting::Setting(std::string key, std::string value)
{
    _key = key;
    _value = value;
}

Setting::Setting(const Setting& other)
{
    std::cout << "Setting Copy constructor called" << std::endl;
}

Setting& Setting::operator=(const Setting& other)
{
    std::cout << "Setting Copy assignment operator called" << std::endl;
    // if (this != &other) {
        // complete here
    // }
    // return *this;
}

Setting::~Setting()
{
    std::cout << "Setting Destructor called" << std::endl;
}

