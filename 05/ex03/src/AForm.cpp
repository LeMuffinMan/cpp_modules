#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute, const std::string& target) 
    : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _target(target) 
{
    _signed = false;
}

AForm::AForm(const AForm& other)
{
    this->_grade_to_execute = other._grade_to_execute;
    this->_grade_to_sign = other._grade_to_sign;
    this->_signed = other._signed;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->_grade_to_execute = other._grade_to_execute;
        this->_grade_to_sign = other._grade_to_sign;
        this->_signed = other._signed;
    }
    return *this;
}

AForm::~AForm()
{
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << form.getName() << " form : signed = " << form.isSigned() << std::endl << "Grade to sign = " << form.getGradeToSign() << std::endl << "Grade to execute = " << form.getGradeToExecute() << std::endl;
    return out;
}

const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const 
{
    return _grade_to_sign;
}

int AForm::getGradeToExecute() const
{
    return _grade_to_execute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw Bureaucrat::GradeTooLowException();
    else
        _signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

const char* AForm::FormOpenFileError::what() const throw() {
    return "Could not create file";
}

const std::string& AForm::getTarget() const
{
    return _target;
}
