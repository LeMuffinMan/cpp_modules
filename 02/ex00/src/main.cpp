#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    //
    // a.setRawBits(2);
    //
    Fixed b( a );
    // 
    // a.setRawBits(4);
    // 
    Fixed c;
    //
    // c.setRawBits(42);
    //
    c = b;
    
    // b.setRawBits(42);
    
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
