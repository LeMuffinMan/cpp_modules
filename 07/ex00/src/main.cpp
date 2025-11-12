#include <iostream>
#include <string>
#include "template.hpp"

int main() {
    int x = 5, y = 10;
    std::cout << "Before swap :" << " x = " << x << " y = " << y << " Type : int" << std::endl;
    swap(x, y);
    std::cout << "After swap : x = " << x << " y = " << y << " Type : int" << std::endl;
    std::cout << "min(x, y) = " << my_min(x, y) << std::endl;
    std::cout << "max(x, y) = " << my_max(x, y) << std::endl;

    std::string s1 = "apple", s2 = "banana";
    std::cout << "Before swap :" << " s1 = " << s1 << " s2 = " << s2 << " Type : string" << std::endl;
    swap(s1, s2);
    std::cout << "min(s1, s2) = " << my_min(s1, s2) << std::endl;
    std::cout << "max(s1, s2) = " << my_max(s1, s2) << std::endl;

    float f1 = 3.14f, f2 = 2.71f;
    std::cout << "Before swap :" << " f1 = " << f1 << " f2 = " << f2 << " Type : float" << std::endl;
    swap(f1, f2);
    std::cout << "min(f1, f2) = " << my_min(f1, f2) << std::endl;
    std::cout << "max(f1, f2) = " << my_max(f1, f2) << std::endl;

    double d1 = 42.24, d2 = 24.42; 
    std::cout << "Before swap :" << " d1 = " << d1 << " d2 = " << d2 << " Type : double" << std::endl;
    swap(d1, d2);
    std::cout << "After swap :" << " d1 = " << d1 << " d2 = " << d2 << " Type : double" << std::endl;
    std::cout << "min(d1, d2) = " << my_min(d1, d2) << std::endl;
    std::cout << "max(d1, d2) = " << my_max(d1, d2) << std::endl;

    char c1 = 'A', c2 = 'Z';
    std::cout << "Before swap :" << " c1 = " << c1 << " c2 = " << c2 << " Type : char" << std::endl;
    swap(c1, c2);
    std::cout << "After swap :" << " c1 = " << c1 << " c2 = " << c2 << " Type : char" << std::endl;
    std::cout << "min(c1, c2) = " << my_min(c1, c2) << std::endl;
    std::cout << "max(c1, c2) = " << my_max(c1, c2) << std::endl;

    return 0;
}

