/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 01:15:51 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/30 16:12:23 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void Weapon::setType(std::string newType) {
    type = newType;
}

const std::string &Weapon::getType() const {
    return type;
}