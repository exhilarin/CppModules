
#include "Harl.hpp"

int main(int ac, char *av[]) 
{
    if (ac != 2)
        return 1;

    Harl harl;
    harl.complain(av);
    return 0;
}
