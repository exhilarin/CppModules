#include "Dog.hpp"
#include "Cat.hpp"

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

    Dog* dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "I want food");
    Dog* dog2 = new Dog(*dog1);

    dog1->getBrain()->setIdea(0, "I want a walk");

    for (int i = 0; i < size; i++)
    {
        std::cout << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }

    std::cout << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << dog2->getBrain()->getIdea(0) << std::endl;

    for (int i = 0; i < size; i++)
        delete animals[i];

    delete dog1;
    delete dog2;

    return 0;
}
