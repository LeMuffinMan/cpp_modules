#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
    std::cout << "AMateria Copy constructor called" << std::endl;
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << "AMateria Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        *this = other;
    }
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria Destructor called" << std::endl;
}

