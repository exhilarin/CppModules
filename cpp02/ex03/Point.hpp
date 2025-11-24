
#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;

    public:
        Point();
        Point(float x, float y);
        Point(const Point &otherClass);
        Point &operator=(const Point &otherClass);
        ~Point();

        const Fixed &getx() const;
        const Fixed &gety() const;
};

std::ostream	&operator<<(std::ostream &out, Point const point);

#endif