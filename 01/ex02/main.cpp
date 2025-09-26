
#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;
    std::cout << "Memory adress of string variable: " << &brain << std::endl;
    std::cout << "Memory adress of stringPTR : " << stringPTR << std::endl;
    std::cout << "Memory adress of stringREF : " << &stringREF << std::endl;
    std::cout << "String variable value : " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR : " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF : " << stringREF << std::endl;
    return (0);
}
