
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    _name = "Default";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &otherClass) : ClapTrap(otherClass) {}

ScavTrap &ScavTrap::operator=(const ScavTrap &otherClass)
{
    if (this != &otherClass)
        ClapTrap::operator=(otherClass);
    return *this;
}

ScavTrap::~ScavTrap() {}

void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints <= 0)
        std::cout << "ScavTrap " << _name << " has no energy to attack!\n";
    else if (_hitPoints <= 0)
        std::cout << "ScavTrap " << _name << " is out of hit points and can't attack!\n";
    else
    {
        std::cout << "ScavTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!\n";
        _energyPoints--;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!\n";
}