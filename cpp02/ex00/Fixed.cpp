
#include "Fixed.hpp"

Fixed::Fixed()
{
    _value = 0;
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &otherClass)
{
    std::cout << "Copy constructor called\n";
    setRawBits(otherClass.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &otherClass)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &otherClass)
        this->setRawBits(otherClass.getRawBits());
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}