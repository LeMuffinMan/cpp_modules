#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    public:
        Fixed(); 
        Fixed(const Fixed& other); 
        Fixed& operator=(const Fixed& other); 
        ~Fixed(); 
        int getRawBits() const;
        void setRawBits(int value);

    private:
        int _fixedPointValue;
        static const int _fractionalBits;
};

#endif
