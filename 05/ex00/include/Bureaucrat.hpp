#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;

    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        //Bureaucrat& operator++();
        //Bureaucrat& operator--();    

        std::string getName() const;
        int getGrade() const;
        void incrementGrade(); //il faut que ce soit des surcharges d'operateur ?
        void decrementGrade();
    class GradeTooHighException: public std::exception {
        public: 
            const char * what() const throw(); //const char * ??
    };

    class GradeTooLowException: public std::exception {
        public: 
            const char * what() const throw(); //virtual ?
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
