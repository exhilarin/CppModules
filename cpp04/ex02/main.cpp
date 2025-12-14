#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < size; i++)
        delete animals[i];

    return 0;
}
