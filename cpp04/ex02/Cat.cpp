
#include "Cat.hpp"

Cat::Cat() : type("Cat")
{
    brain = new Brain();
    std::cout << "Cat constructed!\n";
}

Cat::Cat(const Cat &other) : Animal(other), type(other.type)
{
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructed!\n";
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        *brain = *other.brain;
        Animal::operator=(other);
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called!\n";
}

std::string Cat::getType() const
{
    return type;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow :3\n";
}

Brain *Cat::getBrain() const
{
    return brain;
}