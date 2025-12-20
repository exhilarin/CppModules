
#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria
{
    public:
        Cure();
        Cure(std::string const &type);
        Cure(Cure const &other);
        Cure &operator=(const Cure &other);
        ~Cure();

        AMateria *clone() const;
        virtual void use(ICharacter& target);
};

#endif