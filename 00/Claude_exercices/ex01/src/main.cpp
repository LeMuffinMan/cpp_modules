
#include "Calculator.hpp"
#include <iostream>

int main(void)
{
    Calculator calc;

    calc.add(5);
    calc.multiply(3);
    calc.subtract(5);
    std::cout << "Result: " << calc.getResult() << std::endl; // Result: 13
    calc.clear();
    calc.add(10);
    calc.divide(2);
    std::cout << "Result: " << calc.getResult() << std::endl; // Result: 5 
    calc.divide(0);
    return 0;
}
