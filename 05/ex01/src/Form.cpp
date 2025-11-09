#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) 
{
    //VIER LE TRY CATCH ICI !!!!!
    _signed = false;
    if (grade_to_sign > 150 || grade_to_execute > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade_to_execute < 1 || grade_to_sign < 1)
        throw Bureaucrat::GradeTooHighException();
    else
    {
        _grade_to_sign = grade_to_sign;
        _grade_to_execute = grade_to_execute;
    }
}

Form::Form(const Form& other)
{
    this->_grade_to_execute = other._grade_to_execute;
    this->_grade_to_sign = other._grade_to_sign;
    this->_signed = other._signed;
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->_grade_to_execute = other._grade_to_execute;
        this->_grade_to_sign = other._grade_to_sign;
        this->_signed = other._signed;
    }
    return *this;
}

Form::~Form() {}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << form.getName() << ", form : signed = " << form.isSigned() << std::endl << "Grade to sign = " << form.getGradeToSign() << std::endl << "Grade to execute = " << form.getGradeToExecute() << std::endl;
    return out;
}

const std::string& Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const 
{
    return _grade_to_sign;
}

int Form::getGradeToExecute() const
{
    return _grade_to_execute;
}

const char* Form::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

void Form::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw Bureaucrat::GradeTooLowException();
    else
        _signed = true;
}

void Form::execute(Bureaucrat bureaucrat) const
{
    //VIRER LE TRY THROW ICI !!!!!
    if (_signed == false)
        throw Form::FormNotSignedException();
    else if (bureaucrat.getGrade() > this->getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();
    else
        std::cout << bureaucrat << " executed " << _name << std::endl;
}
