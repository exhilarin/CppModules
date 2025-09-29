/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 01:11:19 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/29 01:31:45 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        HumanB *weapon;
    
    public:
        HumanB(std::string name) : name(name) {}
        void    setWeapon(Weapon &weapon);
        void    attack();
};

#endif