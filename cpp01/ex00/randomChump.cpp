/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 20:15:48 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/28 20:51:48 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie ZombieStack(name);
    ZombieStack.announce(); 
}