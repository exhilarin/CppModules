
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

        bool  bsp( Point const a, Point const b, Point const c, Point const point);
        const Fixed &getx() const;
        const Fixed &gety() const;
};

std::ostream	&operator<<(std::ostream &out, Point const point);

#endif