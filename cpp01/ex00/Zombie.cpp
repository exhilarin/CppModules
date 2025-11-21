
#include "Zombie.hpp"

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void) {
    std::cout << "Zombie " << name << " has died." << std::endl;
}