
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    _name = "Default";
    _hitPoints = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructed!\n";
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
    _hitPoints = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructed!\n";
}

ScavTrap::ScavTrap(const ScavTrap &otherClass) : ClapTrap(otherClass)
{
    std::cout << "ScavTrap " << _name << " copy constructed!\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &otherClass)
{
    if (this != &otherClass)
    {
        ClapTrap::operator=(otherClass);
        std::cout << "ScavTrap " << this->_name << " assigned to " 
            << otherClass._name << "!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << _name << " is already assigned to itself." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destroyed!\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (_energyPoint <= 0)
        std::cout << "ScavTrap " << _name << " has no energy to attack!\n";
    else if (_hitPoints <= 0)
        std::cout << "ScavTrap " << _name << " is out of hit points and can't attack!\n";
    else
    {
        std::cout << "ScavTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!\n";
        _energyPoint--;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!\n";
}