
#include "Character.hpp"
#include "ICharacter.hpp"
#include <iostream>

Character::Character() : name("default") {
    for (int x = 0; x < 4; x++)
        inventory[x] = NULL;
}

Character::Character(std::string const &type) : name(type) {
    for (int x = 0; x < 4; x++)
        inventory[x] = NULL;
}

Character::Character(Character const &other) : name(other.name) {
    for (int x = 0; x < 4; x++)
    {
        if (other.inventory[x])
            inventory[x] = other.inventory[x]->clone();
        else
            inventory[x] = NULL;
    }
}

Character &Character::operator=(const Character &other) {
    if (this != &other)
    {
        for (int x = 0; x < 4; x++)
        {
            if (inventory[x] != NULL)
                delete inventory[x];
            inventory[x] = NULL;
        }
        for (int x = 0; x < 4; x++)
        {
            if (other.inventory[x])
                inventory[x] = other.inventory[x]->clone();
            else
                inventory[x] = NULL;
        }
        this->name = other.name;
    }
    return *this;
}

Character::~Character() {
    for (int x = 0; x < 4; x++)
        delete inventory[x];
}

std::string const &Character::getName() const {
    return name;
}

void Character::equip(AMateria *m)
{
    if (m == NULL)
        return ;
    for (int slot = 0; slot < 4; slot++)
        if (inventory[slot] == NULL) {
            inventory[slot] = m;
            break ;
        }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3)
        return ;
    if (inventory[idx] == NULL)
        return ;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx > 3)
        return ;
    if (inventory[idx] == NULL)
        return ;
    inventory[idx]->use(target);
}
