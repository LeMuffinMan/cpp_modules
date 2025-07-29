
#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;
    std::cout << "Adresse de brain : " << &brain << std::endl;
    std::cout << "Adresse tenue par stringPTR : " << stringPTR << std::endl;
    std::cout << "Adresse tenue par stringREF : " << &stringREF << std::endl;
    std::cout << "Valeur de brain : " << brain << std::endl;
    std::cout << "Valeur pointée par stringPTR : " << *stringPTR << std::endl;
    std::cout << "Valeur référencée par stringREF : " << stringREF << std::endl;
    return (0);
}

