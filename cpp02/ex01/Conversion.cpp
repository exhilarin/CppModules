
#include "Fixed.hpp"

Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called\n";
    setRawBits(n << _fractionalBits);
}

Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called\n";
    setRawBits(roundf(f * (1 << _fractionalBits)));
}

float Fixed::toFloat(void) const
{
    return ((float)getRawBits() / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (getRawBits() >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}