#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testBureaucratCreation() {
    try {
        Bureaucrat high("High", 1);
        std::cout << high << std::endl;
        Bureaucrat low("Low", 150);
        std::cout << low << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try {
        std::cout << "About to instantiate \"Invalid\" bureaucrat with grade 0" << std::endl; 
        Bureaucrat invalid("Invalid", 0); 
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try {
        std::cout << "About to instantiate \"Invalid\" bureaucrat with grade 151" << std::endl; 
        Bureaucrat invalid("Invalid", 151); 
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testGradeModification() {
    Bureaucrat bob("Bob", 2);
    std::cout << "Before inc : " << bob << std::endl;
    try {
        bob.incrementGrade();
        std::cout << "After inc: " << bob << std::endl;
        std::cout << "About to increment to 0: " << bob << std::endl;
        bob.incrementGrade();
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    Bureaucrat mireille("Mireille", 149);
    std::cout << "Before dec : " << mireille << std::endl;
    try {
        mireille.decrementGrade();
        std::cout << "After dec: " << mireille << std::endl;
        std::cout << "About to decrement to 151: " << mireille << std::endl;
        mireille.decrementGrade();
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testShrubberyCreationForm() {
    Bureaucrat gardener("Gardener", 130);
    Bureaucrat unqualified_worker("Unqualified worker", 140);
    ShrubberyCreationForm shrubbery("backyard");
    
    std::cout << shrubbery << std::endl;
    std::cout << gardener << std::endl;

    // execution without signing : should throw an error 
    gardener.executeForm(shrubbery);

    gardener.signForm(shrubbery);

    std::cout << "shrubbery " << shrubbery.getName() << " : " << "signed = " << shrubbery.isSigned() << std::endl;

    gardener.executeForm(shrubbery);

    // execution without grade : should throw an error 
    unqualified_worker.executeForm(shrubbery);

    ShrubberyCreationForm unamed_shrubbery("/root/");

    gardener.signForm(unamed_shrubbery);

    gardener.executeForm(unamed_shrubbery);

    std::cout << std::endl;
}

void testRobotomyRequestForm() {
    Bureaucrat surgeon("Surgeon", 40);
    Bureaucrat intern("Intern", 60);
    RobotomyRequestForm robotomy("HAL-9000");
    
    std::cout << robotomy << std::endl;
    std::cout << surgeon << std::endl;
    
    // should throw an error 
    surgeon.executeForm(robotomy);
    
    surgeon.signForm(robotomy);
    
    for (int i = 0; i < 3; i++) {
        surgeon.executeForm(robotomy);
    }
    
    //should throw an error 
    intern.executeForm(robotomy);
    
    std::cout << std::endl;
}

void testPresidentialPardonForm() {
    Bureaucrat president("President", 1);
    Bureaucrat minister("Minister", 10);
    Bureaucrat secretary("Secretary", 30);
    PresidentialPardonForm pardon("Nicolas");
    
    std::cout << pardon << std::endl;
    std::cout << president << std::endl;
    
    // should throw an error 
    president.executeForm(pardon);
    
    // should throw an error 
    secretary.signForm(pardon);
    
    minister.signForm(pardon);
    
    // should throw an error 
    secretary.executeForm(pardon);
    
    president.executeForm(pardon);
    
    std::cout << std::endl;
}

int main() {
    std::srand(std::time(0));
    std::cout << "=== Bureaucrat creation ===" << std::endl;
    testBureaucratCreation();
    std::cout << "=== Grade modification ===" << std::endl;
    testGradeModification();
    std::cout << "=== Shrubbery creation form ===" << std::endl;
    testShrubberyCreationForm();
    std::cout << "=== Robotomy request form ===" << std::endl;
    testRobotomyRequestForm();
    std::cout << "=== Presidential pardon form ===" << std::endl;
    testPresidentialPardonForm();
    return 0;
}
