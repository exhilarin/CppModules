#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoint = ScavTrap::_energyPoint;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << _name << " constructed!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &otherClass)
    : ClapTrap(otherClass), ScavTrap(otherClass), FragTrap(otherClass)
{
    this->_name = otherClass._name;
    std::cout << "DiamondTrap " << _name << " copy constructed!\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &otherClass)
{
    if (this != &otherClass)
    {
        ClapTrap::operator=(otherClass);
        ScavTrap::operator=(otherClass);
        FragTrap::operator=(otherClass);
        this->_name = otherClass._name;

        std::cout << "DiamondTrap " << _name
                  << " assigned from " << otherClass._name << "!\n";
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " destroyed!\n";
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const
{
    std::cout << "I am DiamondTrap: " << _name
              << ", ClapTrap name: " << ClapTrap::_name << "\n";
}
