
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm("Presidential Pardon Form", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &otherClass)
    : AForm(otherClass), target(otherClass.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &otherClass)
{
    if (this != &otherClass)
    {
        AForm::operator=(otherClass);
        this->target = otherClass.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    checkExecution(executor);
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
