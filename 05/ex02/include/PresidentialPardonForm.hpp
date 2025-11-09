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

    private:
        // std::string     _target;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form);

#endif
