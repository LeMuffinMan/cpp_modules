#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.h"

int main( void )
{
    Point a(0, 0);
    Point b(2, 0);
    Point c(0, 2);
    Point outside(3, 3); 
    Point inside(0.5, 0.5); 
    Point edge(1, 0); 
    Point summit(0, 0);

    std::cout << "Triangle summits coordinates : 0, 0 | 2, 0 | 0, 2" << std::endl << std::endl;
    std::cout << "Point outside tested : 3, 3 --> ";
    if (bsp(a, b, c, outside))
        std::cout << "Point is in triangle" << std::endl;
    else
        std::cout << "Point is NOT in triangle" << std::endl;
    std::cout << "Point is inside tested : 0.5, 0.5 --> ";
    if (bsp(a, b, c, inside))
        std::cout << "Point is in triangle" << std::endl;
    else
        std::cout << "Point is NOT in triangle" << std::endl;
    std::cout << "Point edge tested : 1, 0 --> ";
    if (bsp(a, b, c, edge))
        std::cout << "Point is in triangle" << std::endl;
    else
        std::cout << "Point is NOT in triangle" << std::endl;
    std::cout << "Point summit tested : 0, 0 --> ";
    if (bsp(a, b, c, summit))
        std::cout << "Point is in triangle" << std::endl;
    else
        std::cout << "Point is NOT in triangle" << std::endl;
    return 0;
}
