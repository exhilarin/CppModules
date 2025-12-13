
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage (0) {}

ClapTrap::ClapTrap(std::string _name)
    : _name(_name), _hitPoints(10), _energyPoints(10), _attackDamage (0) {}

ClapTrap::ClapTrap(const ClapTrap &otherClass) 
    : _name(otherClass._name), _hitPoints(otherClass._hitPoints),
        _energyPoints(otherClass._energyPoints), _attackDamage(otherClass._attackDamage) {}

ClapTrap &ClapTrap::operator=(const ClapTrap &otherClass)
{
    if (this != &otherClass)
    {
        _name = otherClass._name;
        _hitPoints = otherClass._hitPoints;
        _energyPoints = otherClass._energyPoints;
        _attackDamage = otherClass._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {}

void ClapTrap::attack(const std::string& target)
{
    if (_attackDamage <= 0)
        std::cout << "ClapTrap " << _name << " has no attack damage to deal!" << std::endl;
    else if (_energyPoints <= 0)
        std::cout << "ClapTrap " << _name << " has no energy to attack!\n";
    else if (_hitPoints <= 0)
        std::cout << "ClapTrap " << _name << " is out of hit points and can't attack!\n";
    else
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " 
            << _attackDamage << " points of damage!\n";
        _energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
        std::cout << "ClapTrap " << _name << " is already destroyed!\n";
    else
    {
        _hitPoints -= amount;
        if (_hitPoints < 0)
            _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount
            << " points of damage! Remaining HP: " << _hitPoints << std::endl;
    }    
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints <= 0)
        std::cout << "ClapTrap " << _name << " has no energy to repair!\n";
    else if (_hitPoints <= 0)
        std::cout << "ClapTrap " << _name << " can't repair because it's destroyed!\n";
    else
    {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " repairs itself, restoring " << amount
            << " hit points! Current HP: "<< _hitPoints << std::endl;
    }
}
