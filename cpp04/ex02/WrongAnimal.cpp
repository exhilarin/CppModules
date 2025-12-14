
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type ("WrongAnimal")
{
    std::cout << "WrongAnimal constructed!\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
    std::cout << "WrongAnimal copy consturected!\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy assignment called\n";
    if (this != &other)
        this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called!\n";
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "The WrongAnimal makes sound!\n";
}