#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int value)
{
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
    _fixedPointValue = other._fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        _fixedPointValue = other._fixedPointValue;
    return *this;
}

Fixed::~Fixed() {}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _fixedPointValue >> _fractionalBits;
}

int Fixed::getRawBits(void) const
{
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    _fixedPointValue = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed& other) const
{
    return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const 
{
    return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const
{
    return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return _fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    long long mul = static_cast<long long>(this->_fixedPointValue) * other._fixedPointValue;
    result.setRawBits(static_cast<int>(mul >> _fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (other._fixedPointValue == 0) {
        std::cout << "Error: Division by zero" << std::endl;
        return Fixed();
    }
    Fixed result;
    long long dividend = (static_cast<long long>(this->_fixedPointValue) << _fractionalBits);
    result.setRawBits(static_cast<int>(dividend / other._fixedPointValue));
    return result;
}

Fixed& Fixed::operator++()
{
    ++_fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++_fixedPointValue;
    return temp;
}

Fixed& Fixed::operator--()
{
    --_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --_fixedPointValue;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}
