
#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type("default") {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(AMateria const &other) : type(other.type) {}

AMateria &AMateria::operator=(const AMateria &other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
   return type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
}