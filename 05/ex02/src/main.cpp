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
        bob.incrementGrade();
        std::cout << "After inc: " << bob << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    Bureaucrat mireille("Mireille", 149);
    std::cout << "Before dec : " << mireille << std::endl;
    try {
        mireille.decrementGrade();
        std::cout << "After dec: " << mireille << std::endl;
        mireille.decrementGrade();
        std::cout << "After dec: " << mireille << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testShrubberyCreationForm() {
    Bureaucrat gardener("Gardener", 130);
    Bureaucrat unqualified_worker("Unqualified worker", 140);
    ShrubberyCreationForm shrubbery("home");
    
    std::cout << shrubbery << std::endl;
    std::cout << gardener << std::endl;
    
    // Try to execute without signing
    gardener.executeForm(shrubbery);
    
    // Sign the form
    gardener.signForm(shrubbery);
    
    // Execute with proper grade
    gardener.executeForm(shrubbery);
    
    // Try with lower grade bureaucrat
    unqualified_worker.executeForm(shrubbery);
    
    std::cout << std::endl;
}

void testRobotomyRequestForm() {
    Bureaucrat surgeon("Surgeon", 40);
    Bureaucrat intern("Intern", 60);
    RobotomyRequestForm robotomy("HAL-9000");
    
    std::cout << robotomy << std::endl;
    std::cout << surgeon << std::endl;
    
    // Try to execute without signing
    surgeon.executeForm(robotomy);
    
    // Sign the form
    surgeon.signForm(robotomy);
    
    // Execute multiple times to see different outcomes
    for (int i = 0; i < 3; i++) {
        surgeon.executeForm(robotomy);
    }
    
    // Try with lower grade bureaucrat
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
    
    // Try to execute without signing
    president.executeForm(pardon);
    
    // secretary tries to sign (should fail)
    secretary.signForm(pardon);
    
    // Minister signs successfully
    minister.signForm(pardon);
    
    // secretary tries to execute (should fail - grade too low)
    secretary.executeForm(pardon);
    
    // President executes successfully
    president.executeForm(pardon);
    
    std::cout << std::endl;
}

void testFormExceptions() {
    try {
        // This should throw GradeTooHighException
        // ShrubberyCreationForm invalidHigh("test", 0, 0);
    } catch (std::exception& e) {
        std::cout << "High grade exception: " << e.what() << std::endl;
    }
    
    try {
        // This should throw GradeTooLowException
        // ShrubberyCreationForm invalidLow("test", 151, 151);
    } catch (std::exception& e) {
        std::cout << "Low grade exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

int main() {
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
    std::cout << "=== Form exceptions ===" << std::endl;
    testFormExceptions();
    return 0;
}
