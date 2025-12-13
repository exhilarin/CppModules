
#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    private:
        std::string type;

    public:
        Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        virtual ~Dog();

        std::string getType() const;
        virtual void makeSound() const;
};

#endif