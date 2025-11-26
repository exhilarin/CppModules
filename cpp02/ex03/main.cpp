#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    Point a(0, 0);
    Point b(5, 0);
    Point c(2, 4);

    Point p(8, 1);

    if (bsp(a, b, c, p))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;

    return 0;
}
