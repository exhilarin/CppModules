/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:36:41 by iguney            #+#    #+#             */
/*   Updated: 2025/12/07 01:07:18 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main()
{
    ClapTrap claptrap1("Clappy");
    ClapTrap claptrap2("Bob");

    std::cout << "\n--- Test 1: Attack with insufficient energy ---\n";
    claptrap1.attack("Bob");

    std::cout << "\n--- Test 2: Attack with sufficient energy but no hit points ---\n";
    claptrap1.takeDamage(10);
    claptrap1.attack("Bob");

    std::cout << "\n--- Test 3: Repair with insufficient energy ---\n";
    claptrap1.beRepaired(5);

    std::cout << "\n--- Test 4: Repair after taking damage ---\n";
    claptrap1.takeDamage(5);
    claptrap1.beRepaired(5);

    std::cout << "\n--- Test 5: Attack after repairing ---\n";
    claptrap1.attack("Bob");

    std::cout << "\n--- Test 6: Copy constructor ---\n";
    ClapTrap claptrap3 = claptrap1;

    std::cout << "\n--- Test 7: Assignment operator ---\n";
    ClapTrap claptrap4("Claptrap4");
    claptrap4 = claptrap1;

    std::cout << "\n--- Test 8: Multiple attacks ---\n";
    claptrap1.attack("Bob");
    claptrap1.attack("Bob");
    claptrap1.attack("Bob");

    std::cout << "\n--- Test 9: Take damage and check health ---\n";
    claptrap1.takeDamage(15);

    std::cout << "\n--- Test 10: Destroyed ClapTrap can't attack ---\n";
    claptrap1.attack("Bob");

    return 0;
}
