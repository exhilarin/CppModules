
#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string type) : type(type) {}
        void setType(std::string newType);
        const std::string &getType() const;
};

#endif