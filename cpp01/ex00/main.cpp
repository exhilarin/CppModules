/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:49:02 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/28 21:06:05 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *heapZombie = newZombie("HeapZ");
    heapZombie->announce();
    randomChump("StackZ");
    delete heapZombie;
    return 0;
}