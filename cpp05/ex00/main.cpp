#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Ali", 2);
        std::cout << a << std::endl;
        a.increaseGrade();
        std::cout << a << std::endl;
        a.increaseGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "------" << std::endl;
    try
    {
        Bureaucrat b("Veli", 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "------" << std::endl;
    try
    {
        Bureaucrat c("Ayse", 150);
        std::cout << c << std::endl;

        c.decreaseGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
