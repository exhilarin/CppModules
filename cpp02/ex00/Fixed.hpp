/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:40:41 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/10/24 23:12:42 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed 
{
    private:
        int                 _value;
        static const int    _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed &otherClass);
        Fixed &operator=(const Fixed &otherClass);
        ~Fixed();
        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif