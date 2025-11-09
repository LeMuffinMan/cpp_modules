#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib> // for rand

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery", 145, 137, "Default"), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery", 145, 137, target), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string& ShrubberyCreationForm::getTarget() const { 
    return _target; 
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open()) {
        throw AForm::FormOpenFileError();
    }

    int treeType = std::rand(); 

    switch (treeType % 2) {
        case 0:
            file << "       _-_" << std::endl;
            file << "    /~~   ~~\\" << std::endl;
            file << " /~~         ~~\\" << std::endl;
            file << "{               }" << std::endl;
            file << " \\  _-     -_  /" << std::endl;
            file << "   ~  \\\\ //  ~" << std::endl;
            file << "_- -   | | _- _" << std::endl;
            file << "  _ -  | |   -_" << std::endl;
            file << "      // \\\\" << std::endl;
            break;
        default:
            file << "       ^" << std::endl;
            file << "      / \\" << std::endl;
            file << "     /   \\" << std::endl;
            file << "    /     \\" << std::endl;
            file << "   /       \\" << std::endl;
            file << "  /         \\" << std::endl;
            file << "  -----------" << std::endl;
            file << "      |||" << std::endl;
            file << "      |||" << std::endl;
            break;
    }
    file.close();
}


