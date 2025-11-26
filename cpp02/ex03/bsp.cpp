
#include "Point.hpp"

int area(Point const &a, Point const &b, Point const &c)
{
    int area = 0;

    int x1 = (a.getx()).toInt();
    int x2 = (b.getx()).toInt();
    int x3 = (c.getx()).toInt();
    int y1 = (a.gety()).toInt();
    int y2 = (b.gety()).toInt();
    int y3 = (c.gety()).toInt();
    
    area = ((x1 * y2) + (x2 * y3) + (x3 * y1) - (x2 * y1) - (x3 * y2) - (x1 * y3));
    if (area < 0)
        area *= -1;

    return area / 2;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    int area_abc = area(a, b, c);
    int area_pbc = area(point, b, c);
    int area_apc = area(a, point, c);
    int area_abp = area(a, b, point);

    if (!(area_pbc * area_apc * area_abp))
        return false;
    if (area_pbc + area_apc + area_abp == area_abc)
        return true;
    return false;
}
