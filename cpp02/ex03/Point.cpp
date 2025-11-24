
#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float x, float y) : _x(x), _y(y) {}

Point::Point(const Point &otherClass) : _x(otherClass._x), _y(otherClass._y) {}

Point &Point::operator=(const Point &otherClass)
{
    if (this != &otherClass)
    {
        this->_x = otherClass._x;
        this->_y = otherClass._y;
    }
    return *this;
}

Point::~Point() {}

const Fixed::Fixed &getx()
{
    return _x;
}

const Fixed &gety() const
{
    return _y;
}