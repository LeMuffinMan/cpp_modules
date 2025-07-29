#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
    Fixed(); // Default constructor
    Fixed(const Fixed& other); // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment
    ~Fixed(); // Destructor
    int getRawBits() const;
    void setRawBits(int value);

private:
    int _fixedPointValue;
    static const int _fractionalBits;
};

#endif
