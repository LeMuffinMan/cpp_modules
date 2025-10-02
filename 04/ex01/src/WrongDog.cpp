#include "WrongDog.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongDog::WrongDog()
{
    std::cout << "WrongDog Default constructor called" << std::endl;
    this->ideas = new Brain();
}

WrongDog::WrongDog(const WrongDog& other)
{
    std::cout << "WrongDog Copy constructor called" << std::endl;
    *this = other;
}

WrongDog& WrongDog::operator=(const WrongDog& other)
{
    std::cout << "WrongDog Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        this->ideas = new Brain();
    }
    return *this;
}

WrongDog::~WrongDog() 
{
    std::cout << "WrongDog Destructor called" << std::endl;
}

void WrongDog::makeSound() const 
{
    std::cout << "Bzzzbz" << std::endl;
}
