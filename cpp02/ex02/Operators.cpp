/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 01:32:37 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/10/25 02:15:18 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Comparison operators
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

// Arithmetic operators
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

// Increment / Decrement
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

// Static min/max
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
