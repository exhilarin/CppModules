
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        Form contract("Contract", 50, 50);

        std::cout << boss << std::endl;
        std::cout << intern << std::endl;
        std::cout << contract << std::endl;

        std::cout << "\nIntern tries to sign:" << std::endl;
        intern.signForm(contract);

        std::cout << "\nBoss signs:" << std::endl;
        boss.signForm(contract);

        std::cout << contract << std::endl;

        std::cout << "\nBoss tries to sign again:" << std::endl;
        boss.signForm(contract);

        std::cout << "\nBoundary test:" << std::endl;
        Bureaucrat top("Top", 1);
        top.increaseGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
