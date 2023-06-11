
#include "Point.h"

int Point::distSquared(const Point& p1, const Point& p2)
{
    return Point(p1 - p2).norm2();
};


Point Point::operator+(const Point &rhs) const
{
    return Point(x + rhs.x, y + rhs.y);
}

Point Point::operator-(const Point &rhs) const
{
    return Point(x - rhs.x, y - rhs.y);
}
