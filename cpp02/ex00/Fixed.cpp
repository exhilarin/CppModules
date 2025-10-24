/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:39:36 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/10/24 23:15:31 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    _value = 0;
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &otherClass)
{
    std::cout << "Copy constructor called\n";
    this->_value = otherClass._value;
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