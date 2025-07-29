#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

// Constructeurs
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    _fixedPointValue = other._fixedPointValue;
}

// Opérateur d'affectation
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
        _fixedPointValue = other._fixedPointValue;
    return *this;
}

// Destructeur
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Conversion
float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

// Accès brut
int Fixed::getRawBits(void) const {
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

// Affichage
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}

// Comparaisons
bool Fixed::operator>(const Fixed& other) const {
    return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const {
    return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const {
    return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _fixedPointValue != other._fixedPointValue;
}

// Arithmétique
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long long mul = static_cast<long long>(this->_fixedPointValue) * other._fixedPointValue;
    result.setRawBits(static_cast<int>(mul >> _fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other._fixedPointValue == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(); // retourne 0
    }
    Fixed result;
    long long dividend = (static_cast<long long>(this->_fixedPointValue) << _fractionalBits);
    result.setRawBits(static_cast<int>(dividend / other._fixedPointValue));
    return result;
}

// Incrémentation / Décrémentation
Fixed& Fixed::operator++() { // pré-incrément
    ++_fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) { // post-incrément
    Fixed temp(*this);
    ++_fixedPointValue;
    return temp;
}

Fixed& Fixed::operator--() { // pré-décrément
    --_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int) { // post-décrément
    Fixed temp(*this);
    --_fixedPointValue;
    return temp;
}

// Fonctions min / max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
