
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;

    public:
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &otherClass);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &otherClass);
        ~PresidentialPardonForm();

        void execute(const Bureaucrat &executor) const;
};

#endif