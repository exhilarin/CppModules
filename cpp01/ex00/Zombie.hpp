/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:40:24 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/11/20 19:57:26 by iguney           ###   ########.fr       */
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
        ~Zombie(void);

        void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
