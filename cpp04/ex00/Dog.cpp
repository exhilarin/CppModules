
#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog constructed!\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructed!\n";
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called!\n";
}

std::string Dog::getType() const
{
    return type;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof :b\n";
}