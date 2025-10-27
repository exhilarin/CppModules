/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:38:53 by iguney            #+#    #+#             */
/*   Updated: 2025/10/27 15:58:19 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    _hitPoints = 100;
    _energyPoint = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructed!\n";
}

FragTrap::FragTrap(const FragTrap &otherClass) : ClapTrap(otherClass)
{
    std::cout << "FragTrap " << _name << " copy constructed!\n";
}

FragTrap &FragTrap::operator=(const FragTrap &otherClass)
{
    if (this != &otherClass)
    {
        ClapTrap::operator=(otherClass);
        std::cout << "FragTrap " << this->_name << " assigned to " 
            << otherClass._name << "!" << std::endl;
    }
    else
        std::cout << "FragTrap " << _name << " is already assigned to itself." << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " destroyed!\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " wants a high five!\n";
}