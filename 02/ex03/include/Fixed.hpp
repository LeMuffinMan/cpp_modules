#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
public:
    Fixed(); // Default constructor
    Fixed(const int value); //new constructor
    Fixed(const float value);
    Fixed(const Fixed& other); // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment
    ~Fixed(); // Destructor

    int getRawBits() const;
    void setRawBits(int value);

    float toFloat(void) const;
    int toInt(void) const;

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();    
    Fixed operator--(int);

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

private:
    int _fixedPointValue;
    static const int _fractionalBits;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
