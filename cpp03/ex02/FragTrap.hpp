
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string _name);
        FragTrap(const FragTrap &otherClass);
        FragTrap &operator=(const FragTrap &otherClass);
        ~FragTrap();

    void highFivesGuys(void);
};

#endif