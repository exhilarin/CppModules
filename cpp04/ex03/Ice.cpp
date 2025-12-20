
#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(std::string const &type) : AMateria(type) {}

Ice::Ice(Ice const &other) : AMateria(other) {}

Ice &Ice::operator=(const Ice &other) {
    AMateria::operator=(other);
    return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}