
#include "Dog.hpp"

Dog::Dog() : type("Dog")
{
    brain = new Brain();
    std::cout << "Dog constructed!\n";
}

Dog::Dog(const Dog &other) : Animal(other), type(other.type)
{
    brain = new Brain(*other.brain);
    std::cout << "Dog copy constructed!\n";
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        *brain = *other.brain;
        Animal::operator=(other);
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
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

Brain *Dog::getBrain() const
{
    return brain;
}