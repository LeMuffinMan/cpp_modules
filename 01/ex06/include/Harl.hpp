#ifndef HARL_H
# define HARL_H

#include <string>

class Harl
{
private:
    void debug();
    void info();
    void warning();
    void error();
    int _filter;

public:
    void complain(std::string level);
};

#endif
