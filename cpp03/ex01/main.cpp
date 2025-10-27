/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:36:41 by iguney            #+#    #+#             */
/*   Updated: 2025/10/27 03:13:15 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Creating ScavTrap objects ===" << std::endl;
    ScavTrap scav1("Serena");
    ScavTrap scav2("Luna");

    std::cout << "\n=== Testing attack() ===" << std::endl;
    scav1.attack("enemy1");
    scav2.attack("enemy2");

    std::cout << "\n=== Testing guardGate() ===" << std::endl;
    scav1.guardGate();
    scav2.guardGate();

    std::cout << "\n=== Testing copy constructor ===" << std::endl;
    ScavTrap scav3(scav1);

    std::cout << "\n=== Testing assignment operator ===" << std::endl;
    scav3 = scav2;

    std::cout << "\n=== Testing energy depletion ===" << std::endl;
    for (int i = 0; i < 55; ++i)  // scav1’in enerjisini bitirmek için
        scav1.attack("target");

    std::cout << "\n=== End of test ===" << std::endl;

    return 0;
}
