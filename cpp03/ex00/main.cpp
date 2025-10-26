/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:36:41 by iguney            #+#    #+#             */
/*   Updated: 2025/10/26 22:10:09 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main()
{
    // ClapTrap nesnesi oluşturuluyor
    ClapTrap claptrap1("Clappy");
    ClapTrap claptrap2("Bob");

    std::cout << "\n--- Test 1: Attack with insufficient energy ---\n";
    claptrap1.attack("Bob");  // Yeterli enerjisi yok, attackDamage == 0

    std::cout << "\n--- Test 2: Attack with sufficient energy but no hit points ---\n";
    claptrap1.takeDamage(10);  // ClapTrap 1 ölecek
    claptrap1.attack("Bob");  // HitPoint == 0, attack yapamamalı

    std::cout << "\n--- Test 3: Repair with insufficient energy ---\n";
    claptrap1.beRepaired(5);  // Enerji yok, onarım yapılamamalı

    std::cout << "\n--- Test 4: Repair after taking damage ---\n";
    claptrap1.takeDamage(5);  // ClapTrap 1 zarar alacak
    claptrap1.beRepaired(5);  // Yeterli enerji olduğu için onarım yapılacak

    std::cout << "\n--- Test 5: Attack after repairing ---\n";
    claptrap1.attack("Bob");  // Attack yapacak, enerjisi var

    std::cout << "\n--- Test 6: Copy constructor ---\n";
    ClapTrap claptrap3 = claptrap1;  // ClapTrap 1 kopyalanacak

    std::cout << "\n--- Test 7: Assignment operator ---\n";
    ClapTrap claptrap4("Claptrap4");
    claptrap4 = claptrap1;  // ClapTrap 1 atama yapılacak

    std::cout << "\n--- Test 8: Multiple attacks ---\n";
    claptrap1.attack("Bob");
    claptrap1.attack("Bob");
    claptrap1.attack("Bob");  // 3 defa saldırı yapılacak

    std::cout << "\n--- Test 9: Take damage and check health ---\n";
    claptrap1.takeDamage(15);  // Zarar alacak, HP düşecek

    std::cout << "\n--- Test 10: Destroyed ClapTrap can't attack ---\n";
    claptrap1.attack("Bob");  // ClapTrap öldü, artık saldıramaz

    return 0;
}
