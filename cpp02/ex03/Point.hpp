
#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed _x;
        const Fixed _y;

    public:
        Point();
        Point(float x, float y);
        Point(const Point &otherClass);
        Point &operator=(const Point &otherClass);
        ~Point();

        const Fixed &getx() const;
        const Fixed &gety() const;
};

#endif