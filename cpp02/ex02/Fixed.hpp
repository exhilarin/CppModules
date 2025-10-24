/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:40:41 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/10/25 01:10:15 by ilyas-guney      ###   ########.fr       */
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

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif