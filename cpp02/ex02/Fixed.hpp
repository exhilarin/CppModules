/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:40:41 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/10/25 01:38:57 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
    private:
        int                 _value;
        static const int    _fractionalBits = 8;
    
    public:
        Fixed();
        Fixed(int const n);
        Fixed(float const f);
        Fixed(const Fixed &otherClass);
        Fixed &operator=(const Fixed &otherClass);
        ~Fixed();
    
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
    
        float   toFloat(void) const;
        int     toInt(void) const;

        // Comparison operators
        bool    operator>(const Fixed &otherClass) const;
        bool    operator<(const Fixed &otherClass) const;
        bool    operator>=(const Fixed &otherClass) const;
        bool    operator<=(const Fixed &otherClass) const;
        bool    operator==(const Fixed &otherClass) const;
        bool    operator!=(const Fixed &otherClass) const;

        // Arithmetic operators
        Fixed   operator+(const Fixed &otherClass) const;
        Fixed   operator-(const Fixed &otherClass) const;
        Fixed   operator*(const Fixed &otherClass) const;
        Fixed   operator/(const Fixed &otherClass) const;

        // Increment / Decrement
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        // Static min / max
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
