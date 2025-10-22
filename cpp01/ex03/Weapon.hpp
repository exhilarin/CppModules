/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 00:43:30 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/30 16:12:32 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string type) : type(type) {}
        void setType(std::string newType);
        const std::string &getType() const;
};

#endif