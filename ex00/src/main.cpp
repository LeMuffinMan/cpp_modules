#include <iostream>
#include <string>
#include "template.hpp"

int main() {
    int a = 2;
    int b = 3;

    std::cout << "Before swap : " << "int a = " << a << " int b = " << b << std::endl;
    swap( a, b );
    std::cout << "After swap : " << "int a = " << a << " int b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    float f1 = 3.14f, f2 = 2.71f;
    std::cout << "Before swap :" << " f1 = " << f1 << " f2 = " << f2 << " Type : float" << std::endl;
    swap(f1, f2);
    std::cout << "After swap :" << " f1 = " << f1 << " f2 = " << f2 << " Type : float" << std::endl;
    std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;
    std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;

    double d1 = 42.24, d2 = 24.42;
    std::cout << "Before swap :" << " d1 = " << d1 << " d2 = " << d2 << " Type : double" << std::endl;
    swap(d1, d2);
    std::cout << "After swap :" << " d1 = " << d1 << " d2 = " << d2 << " Type : double" << std::endl;
    std::cout << "min(d1, d2) = " << ::min(d1, d2) << std::endl;
    std::cout << "max(d1, d2) = " << ::max(d1, d2) << std::endl;

    char c1 = 'A', c2 = 'Z';
    std::cout << "Before swap :" << " c1 = " << c1 << " c2 = " << c2 << " Type : char" << std::endl;
    swap(c1, c2);
    std::cout << "After swap :" << " c1 = " << c1 << " c2 = " << c2 << " Type : char" << std::endl;
    std::cout << "min(c1, c2) = " << ::min(c1, c2) << std::endl;
    std::cout << "max(c1, c2) = " << ::max(c1, c2) << std::endl;

    return 0;
}
