#include "WrongDog.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongDog::WrongDog() : WrongAnimal()
{
    type = "Cerbere";
    std::cout << "WrongDog Default constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other)
{
    std::cout << "WrongDog Copy constructor called" << std::endl;
    this->type = other.type;
}

WrongDog& WrongDog::operator=(const WrongDog& other)
{
    std::cout << "WrongDog Copy assignment operator called" << std::endl;
    if (this != &other)
    {
      this->type = other.type;
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
