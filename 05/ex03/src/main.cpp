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

    // Test creating different forms
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
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << std::endl;

    form = whocares.makeForm("presidential pardon", "Nicolas");
    if (form) {
        boss.signForm(*form);
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
