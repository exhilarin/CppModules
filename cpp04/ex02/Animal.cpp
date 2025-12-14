
#include "Animal.hpp"

Animal::Animal() : type ("Animal")
{
    std::cout << "Animal constructed!\n";
}

Animal::Animal(const Animal &other) : type(other.type)
{
    std::cout << "Animal copy consturected!\n";
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal copy assignment called\n";
    if (this != &other)
        this->type = other.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called!\n";
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "The animal makes sound!\n";
}