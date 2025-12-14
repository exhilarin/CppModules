
#include "Brain.hpp"

Brain::Brain()
{
    for (int x = 0; x < 100; x++)
        ideas[x] = "empty";
}

Brain::Brain(const Brain& other)
{
    for (int x = 0; x < 100; x++)
        this->ideas[x] = other.ideas[x];
}

Brain &Brain::operator=(const Brain& other)
{
    if (this != &other)
        for (int x = 0; x < 100; x++)
            this->ideas[x] = other.ideas[x];
    return *this;
}

Brain::~Brain()
{
    std::cout << "The brain is dead!\n";
}

std::string Brain::setIdea(int x, const std::string& idea)
{
    if (x < 0 || x > 99)
        return "Cannot insert idea: you poked the unreachable corner of the brain :3";
    this->ideas[x] = idea;
    return "Idea successfully implanted into the brain! B)";
}

const std::string &Brain::getIdea(int x) const
{
    static const std::string unreachable = "Oops! You poked the unreachable corner of the brain :b";
    if (x < 0 || x > 99)
        return unreachable;
    return this->ideas[x];
}
