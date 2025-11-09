#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request", 72, 45, "Default"), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45, target), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

const std::string& RobotomyRequestForm::getTarget() const {
    return _target;
}


void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    // Check if form is signed
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    
    // Check if executor has sufficient grade
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }
    
    std::cout << "* drilling noise *" << std::endl;
    if (std::rand() % 2) { 
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed for " << getTarget() << "!" << std::endl;
    }
}
