
#include "Weapon.hpp"

void Weapon::setType(std::string newType) {
    type = newType;
}

const std::string &Weapon::getType() const {
    return type;
}