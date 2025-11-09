#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern() {
    formCreators["shrubbery creation"] = &Intern::createShrubbery;
    formCreators["robotomy request"] = &Intern::createRobotomy;
    formCreators["presidential pardon"] = &Intern::createPresidential;
}

Intern::Intern(const Intern& other) : formCreators(other.formCreators) {}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {
        formCreators = other.formCreators;
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    std::map<std::string, FormCreator>::const_iterator it = formCreators.find(formName);
    
    if (it != formCreators.end()) {
        AForm* form = it->second(target);
        std::cout << "Intern creates " << formName << std::endl;
        return form;
    }
    
    std::cout << "Intern couldn't create form \"" << formName << "\" because it doesn't exist." << std::endl;
    return NULL;
}
