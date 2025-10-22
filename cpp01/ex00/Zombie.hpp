/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:40:24 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/28 20:58:23 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string name;

    public:
        Zombie(std::string name) : name(name) {}
        ~Zombie(void) {std::cout << "Zombie " << name << " has died." << std::endl;}

        void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
