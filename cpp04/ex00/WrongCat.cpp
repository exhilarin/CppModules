
#include "WrongCat.hpp"

WrongCat::WrongCat() : type("WrongCat")
{
    std::cout << "WrongCat constructed!\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other), type(other.type)
{
    std::cout << "WrongCat copy constructed!\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);
        this->type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called!\n";
}

std::string WrongCat::getType() const
{
    return type;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow Meow :3\n";
}