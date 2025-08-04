#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat()
{
    std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    if (this != &other)
    {

    }
    return *this;
}

WrongCat::~WrongCat() 
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const 
{
    std::cout << "Myahouw" << std::endl;
}
