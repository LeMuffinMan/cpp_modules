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
        secretary.decrementGrade();
        std::cout << secretary;
        secretary.incrementGrade();
        std::cout << secretary;
        try {
            secretary.incrementGrade();
        }
        catch (const std::exception& e) {
            std::cout << "Error : " << e.what() << std::endl;
        }
    }




    //
    // Bureaucrat secretary("Jean", 1);
    // Bureaucrat minister("Bob", 150);
    //
    // std::cout << "Trying to increment a low grade bureaucrat" << std::endl;
    // try {
    //     secretary.incrementGrade();
    // }
    // catch (std::exception & e) 
    // {
    //     std::cout << "Error incrementing grade :" << std::endl << secretary;
    // }
    // std::cout << "Trying to decrement a highest grade bureaucrat" << std::endl;
    // try {
    //     minister.decrementGrade();
    // }
    // catch (std::exception & e)
    // {
    //     std::cout << "Error decrementing grade :" << std::endl << secretary;
    // }
    //
    // std::cout << "Trying to instantiate a bureaucrat with 151 grade" << std::endl;
    // Bureaucrat farmer("Bob", 151);
    // std::cout << "Trying to instantiate a bureaucrat with 0 grade" << std::endl;
    // Bureaucrat president("Joe", 0);
    // std::cout << "Trying to instantiate a bureaucrat with -1 grade" << std::endl;
    // Bureaucrat negative("Jim", -1);
    //
    // std::cout << "Regular operations tests :" << std::endl;
    // secretary.decrementGrade();
    // minister.incrementGrade();

    return 0;
}
