
#include "Point.hpp"

float area(Point const &a, Point const &b, Point const &c)
{
    float area = 0;

    float x1 = (a.getx()).toFloat();
    float x2 = (b.getx()).toFloat();
    float x3 = (c.getx()).toFloat();
    float y1 = (a.gety()).toFloat();
    float y2 = (b.gety()).toFloat();
    float y3 = (c.gety()).toFloat();
    
    area = ((x1 * y2) + (x2 * y3) + (x3 * y1) - (x2 * y1) - (x3 * y2) - (x1 * y3));
    if (area < 0)
        area *= -1;

    return area / 2;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float area_abc = area(a, b, c);
    float area_pbc = area(point, b, c);
    float area_apc = area(a, point, c);
    float area_abp = area(a, b, point);

    if (!(area_pbc * area_apc * area_abp))
        return false;
    if (area_pbc + area_apc + area_abp == area_abc)
        return true;
    return false;
}
