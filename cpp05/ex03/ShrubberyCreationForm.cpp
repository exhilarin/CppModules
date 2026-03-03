
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("Shrubbery Creation Form", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &otherClass)
    : AForm(otherClass), target(otherClass.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &otherClass)
{
    if (this != &otherClass)
    {
        AForm::operator=(otherClass);
        this->target = otherClass.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const 
{
    checkExecution(executor);

    std::ofstream ofs((this->target + "_shrubbery").c_str());
    if (!ofs)
    {
        std::cerr << "Error: Could not create file." << std::endl;
        return;
    }

    ofs << "       _-_" << std::endl;
    ofs << "    /~~   ~~\\" << std::endl;
    ofs << " /~~         ~~\\" << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  /" << std::endl;
    ofs << "   ~  \\\\ //  ~" << std::endl;
    ofs << "_- -   | |     _-" << std::endl;
    ofs << "  _ -  | |   -_" << std::endl;
    ofs << "      // \\\\" << std::endl;

    ofs.close();
}
