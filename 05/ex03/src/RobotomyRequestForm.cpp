#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request", 72, 45, "Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45, target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    
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
