#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        std::string _name;
        bool _signed;
        int _grade_to_sign;
        int _grade_to_execute;
    public:
        Form(std::string name, int grade_to_sign, int grade_to_execute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string& getName() const;
        bool isSigned() const; 
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat bureaucrat);
        void execute(Bureaucrat bureaucrat) const;
        class GradeTooHighException : public std::exception {
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            const char* what() const throw();
        };

        class FormNotSignedException: public std::exception {
            const char * what() const throw(); 
        };
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
