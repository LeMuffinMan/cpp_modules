#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
    std::cout << "Fixed Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Fixed Copy constructor called" << std::endl;
    this->_fixedPointValue = other._fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Fixed Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Fixed Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int value)
{
   this->_fixedPointValue = value; 
}

