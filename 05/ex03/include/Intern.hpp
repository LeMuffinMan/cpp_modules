#ifndef INTERN_HPP
#define INTERN_HPP

#include <map>
#include "AForm.hpp"

class AForm;

class Intern
{
    private:
        typedef AForm* (*FormCreator)(const std::string&);
        std::map<std::string, FormCreator> formCreators;

        static AForm* createShrubbery(const std::string& target);
        static AForm* createRobotomy(const std::string& target);
        static AForm* createPresidential(const std::string& target);

    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif
