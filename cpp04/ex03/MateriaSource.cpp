
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int x = 0; x < 4; x++)
        templates[x] = NULL;
}
        
MateriaSource::MateriaSource(const MateriaSource &other) {
    for (int x = 0; x < 4; x++)
    {
        if (other.templates[x])
            templates[x] = other.templates[x]->clone();
        else
            templates[x] = NULL;
    }
}
        
MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other)
    {
        for (int x = 0; x < 4; x++)
        {
            if (templates[x] != NULL)
                delete templates[x];
            templates[x] = NULL;
        }
        for (int x = 0; x < 4; x++)
        {
            if (other.templates[x])
                templates[x] = other.templates[x]->clone();
            else
                templates[x] = NULL; 
        }
    }
    return *this;
}
        
MateriaSource::~MateriaSource() {
    for (int x = 0; x < 4; x++)
        delete templates[x];
}

void MateriaSource::learnMateria(AMateria *m) {
    if (m == NULL)
        return ;
    for (int slot = 0; slot < 4; slot++)
    {
        if (templates[slot] == NULL) {
            templates[slot] = m->clone();
            break ;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const & type) {
    for (int x = 0; x < 4; x++)
        if (templates[x] && templates[x]->getType() == type)
            return templates[x]->clone();
    return NULL;
}