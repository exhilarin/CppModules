#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));

    Bureaucrat low("Bob", 150);
    Bureaucrat mid("Alice", 50);
    Bureaucrat high("Charles", 1);

    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Marvin");

    std::cout << "\n--- Signing Forms ---\n";
    low.signForm(shrubbery);     
    high.signForm(shrubbery);    
    mid.signForm(robotomy);      
    high.signForm(robotomy);     
    high.signForm(pardon);       

    std::cout << "\n--- Executing Forms ---\n";
    low.executeForm(shrubbery);     
    high.executeForm(shrubbery);    
    mid.executeForm(robotomy);      
    high.executeForm(robotomy);     
    high.executeForm(pardon); 

    return 0;
}