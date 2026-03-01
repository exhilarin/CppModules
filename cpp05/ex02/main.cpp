#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL)); // Random seed, C++98

    // Bureaucrat oluştur
    Bureaucrat low("Bob", 150);
    Bureaucrat mid("Alice", 50);
    Bureaucrat high("Charles", 1);

    // Formlar oluştur
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Marvin");

    // Test sign işlemleri
    std::cout << "\n--- Signing Forms ---\n";
    low.signForm(shrubbery);      // fail
    high.signForm(shrubbery);     // success
    mid.signForm(robotomy);       // fail
    high.signForm(robotomy);      // success
    high.signForm(pardon);        // success

    // Test execute işlemleri
    std::cout << "\n--- Executing Forms ---\n";
    try {shrubbery.execute(high);}   catch (std::exception &e) { std::cerr << e.what() << std::endl; }
    try {robotomy.execute(mid);}  catch (std::exception &e) { std::cerr << e.what() << std::endl; }
    try {robotomy.execute(high);}    catch (std::exception &e) { std::cerr << e.what() << std::endl; }
    try {pardon.execute(high);}   catch (std::exception &e) { std::cerr << e.what() << std::endl; }
    try {pardon.execute(low);}     catch (std::exception &e) { std::cerr << e.what() << std::endl; }

    return 0;
}