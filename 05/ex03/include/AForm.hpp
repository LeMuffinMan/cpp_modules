#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        std::string _name;
        bool _signed;
        int _grade_to_sign;
        int _grade_to_execute;

    protected:
        const std::string _target;

    public:
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        AForm(const std::string& name, int grade_to_sign, int grade_to_execute, const std::string& target);

        const std::string& getName() const;
        bool isSigned() const; 
        int getGradeToSign() const;
        int getGradeToExecute() const;
        const std::string& getTarget() const;

        // Member functions
        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const& executor) const = 0; 
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw(); 
        };

        class FormOpenFileError: public std::exception {
            public: 
                const char * what() const throw(); 
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
