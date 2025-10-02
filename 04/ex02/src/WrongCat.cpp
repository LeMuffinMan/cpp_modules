#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat()
{
    std::cout << "WrongCat Default constructor called" << std::endl;
    this->_brain = new Brain();
}

WrongCat::WrongCat(const WrongCat& other)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        this->_brain = new Brain();
    }
    return *this;
}

WrongCat::~WrongCat() 
{
    delete _brain;
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const 
{
    std::cout << "Myahouw" << std::endl;
}
