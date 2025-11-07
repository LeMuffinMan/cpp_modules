#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
    std::cout << "Regular tests : " << std::endl;
    {
        Bureaucrat secretary("Smith", 1);
        std::cout << secretary;
    }
    {
        Bureaucrat secretary("Anderson", 150);
        std::cout << secretary << std::endl;
    }
    {
        Bureaucrat secretary("Morpheus", 75);
        std::cout << secretary << std::endl;
    }
    std::cout << "Error tests : ";
    {
        try {
            Bureaucrat secretary("Anderson", 151);
        }
        catch (const std::exception& e) {
            std::cout << "Error : " << e.what() << std::endl;
        }  
    }
    {
        try {
            Bureaucrat secretary("Anderson", 0);
        }
        catch (const std::exception& e) {
            std::cout << "Error : " << e.what() << std::endl;
        }  
    }
    {
        Bureaucrat secretary("Neo", 1);
        std::cout << secretary;
        secretary.decrementGrade(); // should be grade 2
        std::cout << secretary;
        secretary.incrementGrade(); // should be grade 1
        std::cout << secretary;
        try { 
            secretary.incrementGrade();
        }
        catch (const std::exception& e) {
            std::cout << "Error : " << e.what() << std::endl;
        }
        std::cout << secretary; // should be still 1 since the error was thrown

    }
    return 0;
}
