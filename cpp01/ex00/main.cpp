
#include "Zombie.hpp"

int main(void)
{
    Zombie *heapZombie = newZombie("HeapZ");
    heapZombie->announce();
    randomChump("StackZ");
    delete heapZombie;
    return 0;
}
