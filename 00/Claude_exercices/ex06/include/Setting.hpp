#ifndef SETTING_HPP
#define SETTING_HPP

#include <string>

class Setting
{
public:
    Setting(); //default constructor 
    Setting(std::string key, std::string value);
    Setting(const Setting& other); // Copy constructor
    Setting& operator=(const Setting& other); // Copy assignment
    ~Setting(); // Destructor

    int asInt();
    bool asBool();
    std::string asString();
    double asDouble();
private:
    std::string _key;
    std::string _value;
};

#endif
