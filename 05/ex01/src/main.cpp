#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    std::cout << "=== Form construction with valid grades ===" << std::endl;
    try {
        Form form1("Free money", 75, 100);
        Form form2("Tax exemption", 1, 1);
        Form form3("Low priority", 150, 150);
        
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "=== Form with invalid grades ===" << std::endl;
    std::cout << "0 grade to sign : ";
    try {
        Form form4("Invalid high", 0, 100);
    }
    catch (const std::exception& e) {
        std::cout <<  e.what() << std::endl;
    }

    std::cout << "151 grade to execute : ";
    try {
        Form form5("Invalid low", 75, 151);
    }
    catch (const std::exception& e) {
        std::cout <<  e.what() << std::endl;
    }

    std::cout << std::endl << "=== Bureaucrat creation ===" << std::endl;
    try {
        Bureaucrat deputy("Billy", 76);
        Bureaucrat secretary("Jeff", 101);
        Bureaucrat director("Carl", 1);
        Bureaucrat intern("Tim", 150);
        
        std::cout << deputy << std::endl;
        std::cout << secretary << std::endl;
        std::cout << director << std::endl;
        std::cout << intern << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Form signing ===" << std::endl;
    Form form("Free money", 75, 100);
    Bureaucrat deputy("Billy", 76);
    Bureaucrat secretary("Jeff", 101);
    Bureaucrat director("Carl", 1);

    std::cout << "Before signing: " << form.getName() << " isSigned() = " << form.isSigned() << std::endl;

    try {
        std::cout << deputy << " Attempts to sign: " << form.getName() << std::endl; 
        deputy.signForm(form);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << secretary << " Attempts to sign: " << form.getName() << std::endl;
        secretary.signForm(form);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << director << " Attempts to sign: " << form.getName() << std::endl;
        director.signForm(form);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "After signing " << form.getName() << " isSigned() = " << form.isSigned() << std::endl;

    std::cout << std::endl << "=== Form execution ===" << std::endl;
    try {
        Form form("Free money", 75, 100);
        Bureaucrat deputy("Billy", 76);
        Bureaucrat secretary("Jeff", 101);
        Bureaucrat director("Carl", 1);

        director.signForm(form);

        std::cout << deputy << " attempts to execute: " << form.getName() << std::endl;
        deputy.executeForm(form);

        std::cout << secretary << " attempts to execute: " << form.getName() << std::endl;
        secretary.executeForm(form);

        std::cout << director << " attempts to execute: " << form.getName() << std::endl;
        director.executeForm(form);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Execution without signature ===" << std::endl;
    try {
        Form form("Important document", 50, 50);
        Bureaucrat bureaucrat("John", 1);
        bureaucrat.executeForm(form);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}

