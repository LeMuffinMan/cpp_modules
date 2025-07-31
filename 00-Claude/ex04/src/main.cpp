#include "MyString.hpp"
#include <iostream>

int main(void)
{
    MyString str1("Hello");
    MyString str2(" World");
    std::cout << "compare different strings : " << str1.compare(str2) << std::endl;
    std::cout << "compare same string : " << str1.compare(str1) << std::endl;
    str1.append(str2);
    std::cout << str1.c_str() << std::endl; // Hello World

    MyString str3 = str1; // Copy constructor
    str3.append("!");
    std::cout << str3.c_str() << std::endl; // Hello World!
    std::cout << "length = " << str3.length() << std::endl;
    return 0;
}
