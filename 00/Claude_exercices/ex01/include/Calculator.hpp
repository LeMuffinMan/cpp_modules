#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

class Calculator
{
public:
    Calculator(); // Default constructor
    
    void add(int value);
    void subtract(int value);
    void multiply(int value);
    void divide(int value);
    void clear();
    int getResult();
private:
    int _result;
};

#endif
