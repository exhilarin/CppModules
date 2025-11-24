
#include "Fixed.hpp"

Fixed::Fixed()
{
    _value = 0;
}

Fixed::Fixed(const Fixed &otherClass)
{
    this->_value = otherClass._value;
}

Fixed &Fixed::operator=(const Fixed &otherClass)
{
    if (this != &otherClass)
        this->setRawBits(otherClass.getRawBits());
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

