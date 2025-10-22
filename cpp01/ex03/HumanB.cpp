/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:47:12 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/30 16:13:35 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &weapon)
{
    if (!this->weapon)
        this->weapon = &weapon;
    else
        this->weapon->setType(weapon.getType());
}

void HumanB::attack()
{
    if (this->weapon == NULL)
    {
        std::cout << this->name << " has no weapon to attack with!" << std::endl;
        return;
    }
    else
        std::cout << this->name << " attacks with their " 
            << this->weapon->getType() << std::endl;
}