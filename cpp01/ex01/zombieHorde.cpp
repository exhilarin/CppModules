/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:38:22 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/29 00:03:10 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *Horde = new Zombie[N];
    for (int i = 0; i < N; i++)
        Horde[i] = Zombie(name);
    return Horde;
}