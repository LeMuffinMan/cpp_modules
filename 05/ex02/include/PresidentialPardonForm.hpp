#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        const std::string& getTarget() const;
        void execute(const Bureaucrat& executor) const;

        // class GradeTooHighException : public std::exception {
        //     public:
        //         const char* what() const throw();
        // };
        //
        // class GradeTooLowException : public std::exception {
        //     public:
        //         const char* what() const throw();
        // };
        //
        // class FormNotSignedException : public std::exception {
        //     public:
        //         const char* what() const throw(); 
        // };
    private:
		std::string					_target;
};

#endif
