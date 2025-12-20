
#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat constructed!\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructed!\n";
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat()
{
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