/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:39:36 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/10/25 01:59:43 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

Fixed::~Fixed()
{
    
}

int Fixed::getRawBits(void) const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

