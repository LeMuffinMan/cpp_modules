#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    this->_type = other._type;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &other)
    {
       this->_type = other._type; 
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}

void Animal::makeSound() const
{
    std::cout << "Meoof" << std::endl; 
}
