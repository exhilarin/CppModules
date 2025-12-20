
#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
    public:
        Ice();
        Ice(std::string const &type);
        Ice(Ice const &other);
        Ice &operator=(const Ice &other);
        ~Ice();

        AMateria *clone() const;
        virtual void use(ICharacter& target);
};

#endif