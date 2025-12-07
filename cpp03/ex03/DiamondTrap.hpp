
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap(std::string _name);
        DiamondTrap(const DiamondTrap &otherClass);
        DiamondTrap &operator=(const DiamondTrap &otherClass);
        ~DiamondTrap();

        void attack(const std::string &target);
        void whoAmI() const;
};

#endif