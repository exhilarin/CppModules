/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 00:47:54 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/29 01:07:37 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon &weapon;

    public:
        HumanA(std::string name, Weapon &weapon) 
            : name(name), weapon(weapon) {}
        void attack();
};


#endif