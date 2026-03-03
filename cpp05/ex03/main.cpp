
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        std::cout << *rrf << std::endl;
        delete rrf;
    }

    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (scf)
    {
        std::cout << *scf << std::endl;
        delete scf;
    }

    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Alice");
    if (ppf)
    {
        std::cout << *ppf << std::endl;
        delete ppf;
    }

    AForm* unknown = someRandomIntern.makeForm("unknown form", "Target");
    if (unknown)
        delete unknown;

    return 0;
}
