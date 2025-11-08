#include "Bureaucrat.hpp"
#include <iostream>

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high !";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low !";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade == 1) // ICI c'etait inverse !!! checker les exos precedents !!!
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade == 150) // ICI c'etait inverse !!! checker les exos precedents !!!
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}

void Bureaucrat::signForm(AForm& form) const
{
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->_name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm& form) const
{
    try {
        form.execute(*this); //changer beExecute pour les exo precedents 
        // std::cout << *this << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << *this << " couldn't executed " << form.getName()
                << " because " << e.what() << std::endl;
    }
}
