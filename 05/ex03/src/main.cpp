#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    Intern whocares;
    Bureaucrat boss("Boss", 1);
    AForm* form;

    std::cout << "\n=== Testing Intern Form Creation ===\n" << std::endl;

    form = whocares.makeForm("shrubbery creation", "frontyard");
    if (form) {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << std::endl;

    form = whocares.makeForm("robotomy request", "Bender");
    if (form) {
        try {
            boss.signForm(*form);
        } catch (const std::exception& e) {
            std::cout << form->getName() << " couldn't sign " << form->getName() 
                    << " because " << e.what() << std::endl;
        }
        boss.executeForm(*form);
        delete form;
    }

    std::cout << std::endl;

    form = whocares.makeForm("presidential pardon", "Pierre");
    if (form) {
        try {
            boss.signForm(*form);
        } catch (const std::exception& e) {
            std::cout << form->getName() << " couldn't sign " << form->getName() 
                    << " because " << e.what() << std::endl;
        }
        boss.executeForm(*form);
        delete form;
    }

    std::cout << std::endl;

    form = whocares.makeForm("invalid form", "nowhere");
    if (form) {
        delete form;
    }

    return 0;
}
