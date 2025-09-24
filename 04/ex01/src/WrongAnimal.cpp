#include "WrongAnimal.hpp"
#include "AAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const 
{
    std::cout << "Croa" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}
