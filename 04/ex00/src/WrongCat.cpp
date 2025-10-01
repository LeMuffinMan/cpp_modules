#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
    type = "Miaouss";
    std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    if (this != &other)
    {
       this->type = other.type; 
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
