/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:00:03 by iguney            #+#    #+#             */
/*   Updated: 2025/10/27 03:13:32 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        
    public:
        ScavTrap(std::string _name);
        ScavTrap(const ScavTrap &otherClass);
        ScavTrap &operator=(const ScavTrap &otherClass);
        ~ScavTrap();

        void attack(const std::string& target);
        void guardGate();
};

#endif