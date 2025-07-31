#ifndef SETTING_HPP
#define SETTING_HPP

class Setting
{
public:
    Setting(std::string key, std::string value); // Default constructor
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
