/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:40:24 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/29 00:12:27 by ilyas-guney      ###   ########.fr       */
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
        Zombie(void) {}
        Zombie(std::string name) : name(name) {}

        void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
