/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:49:02 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/29 00:14:20 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int N;

    N = 3;
    Zombie *Horde = zombieHorde(N, "Zombies");
    for (int i = 0; i < N; i++)
        Horde[i].announce();
    delete[] Horde;
}