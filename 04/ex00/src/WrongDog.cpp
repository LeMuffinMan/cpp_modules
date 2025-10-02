#include "WrongDog.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongDog::WrongDog() : WrongAnimal()
{
    _type = "Cerbere";
    std::cout << "WrongDog Default constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other)
{
    std::cout << "WrongDog Copy constructor called" << std::endl;
    this->_type = other._type;
}

WrongDog& WrongDog::operator=(const WrongDog& other)
{
    std::cout << "WrongDog Copy assignment operator called" << std::endl;
    if (this != &other)
    {
      this->_type = other._type;
    }
    return *this;
}

WrongDog::~WrongDog() 
{
    std::cout << "WrongDog Destructor called" << std::endl;
}

void WrongDog::makeSound() const 
{
    std::cout << "Bzbzzz" << std::endl;
}
