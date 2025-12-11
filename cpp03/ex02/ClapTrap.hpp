
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string _name;
        int         _hitPoints;
        int         _energyPoint;
        int         _attackDamage;

    public:
        ClapTrap();
        ClapTrap(std::string _name);
        ClapTrap(const ClapTrap &otherClass);
        ClapTrap &operator=(const ClapTrap &otherClass);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
