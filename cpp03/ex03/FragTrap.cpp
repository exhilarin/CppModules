
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    _name = "Default";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &otherClass) : ClapTrap(otherClass) {}

FragTrap &FragTrap::operator=(const FragTrap &otherClass)
{
    if (this != &otherClass)
        ClapTrap::operator=(otherClass);
    return *this;
}

FragTrap::~FragTrap() {}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " wants a high five!\n";
}