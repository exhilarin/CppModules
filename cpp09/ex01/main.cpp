
#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./program <expression>" << std::endl;
        return 1;
    }
    
    RPN program;
    program.calculate(av[1]);
    return 0;
}