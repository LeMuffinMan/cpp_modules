#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
    std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
    std::cout << "AMateria Copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << "AMateria Copy assignment operator called" << std::endl;
    if (this != &other)
    {

    }
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria Destructor called" << std::endl;
}

