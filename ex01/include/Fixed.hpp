#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other); 
        Fixed& operator=(const Fixed& other);
        ~Fixed(); 
        int getRawBits() const;
        void setRawBits(int value);
        float toFloat(void) const;
        int toInt(void) const;

    private:
        int _fixedPointValue;
        static const int _fractionalBits;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
