
#include "Fixed.hpp"

bool Fixed::operator>(const Fixed &otherClass) const
{
    return this->getRawBits() > otherClass.getRawBits();
}

bool Fixed::operator<(const Fixed &otherClass) const
{
    return this->getRawBits() < otherClass.getRawBits();
}

bool Fixed::operator>=(const Fixed &otherClass) const
{
    return this->getRawBits() >= otherClass.getRawBits();
}

bool Fixed::operator<=(const Fixed &otherClass) const
{
    return this->getRawBits() <= otherClass.getRawBits();
}

bool Fixed::operator==(const Fixed &otherClass) const
{
    return this->getRawBits() == otherClass.getRawBits();
}

bool Fixed::operator!=(const Fixed &otherClass) const
{
    return this->getRawBits() != otherClass.getRawBits();
}

Fixed Fixed::operator+(const Fixed &otherClass) const
{
    return Fixed(this->toFloat() + otherClass.toFloat());
}

Fixed Fixed::operator-(const Fixed &otherClass) const
{
    return Fixed(this->toFloat() - otherClass.toFloat());
}

Fixed Fixed::operator*(const Fixed &otherClass) const
{
    return Fixed(this->toFloat() * otherClass.toFloat());
}

Fixed Fixed::operator/(const Fixed &otherClass) const
{
    return Fixed(this->toFloat() / otherClass.toFloat());
}

Fixed &Fixed::operator++()
{
    ++this->_value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_value++;
    return temp;
}

Fixed &Fixed::operator--()
{
    --this->_value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_value--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a.getRawBits() < b.getRawBits()) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a.getRawBits() > b.getRawBits()) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() > b.getRawBits()) ? a : b;
}
