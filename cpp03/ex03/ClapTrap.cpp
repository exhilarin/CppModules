
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("Default"), _hitPoints(10), _energyPoint(10), _attackDamage (0)
{
    std::cout << "ClapTrap " << _name << " constructed!\n";
}

ClapTrap::ClapTrap(std::string _name)
    : _name(_name), _hitPoints(10), _energyPoint(10), _attackDamage (0)
{
    std::cout << "ClapTrap " << _name << " constructed!\n";
}

ClapTrap::ClapTrap(const ClapTrap &otherClass) 
    : _name(otherClass._name), _hitPoints(otherClass._hitPoints),
        _energyPoint(otherClass._energyPoint), _attackDamage(otherClass._attackDamage)
{
    std::cout << "ClapTrap " << _name << " copy constructed!\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &otherClass)
{
    if (this != &otherClass)
    {
        std::cout << "ClapTrap " << _name << " assigned to " 
            << otherClass._name << "!" << std::endl;
        _name = otherClass._name;
        _hitPoints = otherClass._hitPoints;
        _energyPoint = otherClass._energyPoint;
        _attackDamage = otherClass._attackDamage;
    }
    else
        std::cout << "ClapTrap " << _name << " is already assigned to itself." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destroyed!\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (_attackDamage <= 0)
        std::cout << "ClapTrap " << _name << " has no attack damage to deal!" << std::endl;
    else if (_energyPoint <= 0)
        std::cout << "ClapTrap " << _name << " has no energy to attack!\n";
    else if (_hitPoints <= 0)
        std::cout << "ClapTrap " << _name << " is out of hit points and can't attack!\n";
    else
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " 
            << _attackDamage << " points of damage!\n";
        _energyPoint--;
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
    if (_energyPoint <= 0)
        std::cout << "ClapTrap " << _name << " has no energy to repair!\n";
    else if (_hitPoints <= 0)
        std::cout << "ClapTrap " << _name << " can't repair because it's destroyed!\n";
    else
    {
        _energyPoint--;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " repairs itself, restoring " << amount
            << " hit points! Current HP: "<< _hitPoints << std::endl;
    }
}
