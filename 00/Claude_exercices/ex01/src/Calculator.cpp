#include "Calculator.hpp"
#include <iostream>

Calculator::Calculator()
{
    std::cout << "Calculator Default constructor called" << std::endl;
    _result = 0;
}

void Calculator::add(int value)
{
    _result = _result + value;
}

void Calculator::subtract(int value)
{
    _result = _result - value;
}

void Calculator::multiply(int value)
{
    _result = _result * value;
}

void Calculator::divide(int value)
{
    if (value == 0)
    {
        std::cout << "Error: division by 0 is forbidden" << std::endl;
        return ;
    }
    _result = _result / value;
}

void Calculator::clear()
{
    _result = 0;
}

int Calculator::getResult()
{
    return _result;
}
