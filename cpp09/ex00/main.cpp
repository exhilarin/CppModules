
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./program <filename>" << std::endl;
        return 1;
    }

    std::string filename = av[1];

    BitcoinExchange program;
    program.execute(filename);
}