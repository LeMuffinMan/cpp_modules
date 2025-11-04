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
    //Try pour l'attribution de grade
    //Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    this->_grade = other._grade;
    //Try pour l'attribution de grade
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
    //Try pour l'attribution de grade
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat " << bureaucrat.getGrade() << "." << std::endl;
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
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooLowException(); // low ou high ?
    else
        this->_grade--;
    //Try pour l'attribution de grade : doivent throw la meme exception que le constructeur 
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade++;
}

