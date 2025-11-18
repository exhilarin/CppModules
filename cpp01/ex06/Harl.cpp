
#include "Harl.hpp"

void Harl::debug(void) 
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my "
              << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
              << "I really do!" << std::endl << std::endl;
}

void Harl::info(void) 
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. "
              << "You didn’t put enough bacon in my burger! "
              << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void) 
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. "
              << "I’ve been coming for years whereas you started working here last month."
              << std::endl << std::endl;
}

void Harl::error(void) 
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! "
              << "I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(Message level)
{
    switch (level)
    {
        case DEBUG:
            debug();
            break;
        case INFO:
            info();
            break;
        case WARNING:
            warning();
            break;
        case ERROR:
            error();
            break;
        default:
            break;
    }
}
