#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
    _type = "Miaouss";
    std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    this->_type = other._type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    if (this != &other)
    {
       this->_type = other._type; 
    }
    return *this;
}

WrongCat::~WrongCat() 
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const 
{
    std::cout << "Croa" << std::endl;
}
