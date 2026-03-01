
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    public:
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &otherClass);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &otherClass);
        ~ShrubberyCreationForm();

        void execute(const Bureaucrat &executor) const;
};

#endif