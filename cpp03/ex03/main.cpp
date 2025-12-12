
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\n=== Test 1: Default Constructor ===\n";
    DiamondTrap d1;
    d1.whoAmI();
    d1.attack("Enemy A");

    std::cout << "\n=== Test 2: Name Constructor ===\n";
    DiamondTrap d2("Warrior");
    d2.whoAmI();
    d2.attack("Enemy B");

    std::cout << "\n=== Test 3: Copy Constructor ===\n";
    DiamondTrap d3(d2);
    d3.whoAmI();
    d3.attack("Enemy C");

    std::cout << "\n=== Test 4: Assignment Operator ===\n";
    DiamondTrap d4;
    d4 = d2;
    d4.whoAmI();
    d4.attack("Enemy D");

    std::cout << "\n=== End of Scope, Destructors will be called ===\n";
    return 0;
}
