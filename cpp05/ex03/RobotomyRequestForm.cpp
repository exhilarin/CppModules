
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &otherClass)
    : AForm(otherClass), target(otherClass.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &otherClass)
{
    if (this != &otherClass)
    {
        AForm::operator=(otherClass);
        this->target = otherClass.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    checkExecution(executor);
    std::cout << "Trrrummm... ";
    std::cout << "Trrrummm... ";
    std::cout << "Trrrummm! " << std::endl;

    std::cout << "Trak... ";
    std::cout << "Tiki... ";
    std::cout << "Tak! " << std::endl;

    int random = std::rand() % 2;

    if (random == 1)
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Failed to robotomize " << this->target << "." << std::endl;
}
