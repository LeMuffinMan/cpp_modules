#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(void); 
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void execute(const Bureaucrat& executor) const;
        const std::string& getTarget() const;
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
		std::string	_target;
};

#endif
