
#include "Zombie.hpp"

int main(void)
{
    int N;

    N = 3;
    Zombie *Horde = zombieHorde(N, "Zombies");
    for (int i = 0; i < N; i++)
        Horde[i].announce();
    delete[] Horde;
}
