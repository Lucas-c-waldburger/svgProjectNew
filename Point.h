
#ifndef SVGPROJECTNEW_POINT_H
#define SVGPROJECTNEW_POINT_H
#include <iostream>


class Point
{
public:
    Point() : x(0), y(0) {}
    Point(int xin, int yin) : x(xin), y(yin) {}

    int norm2() const { return x*x + y*y; }

    Point operator+(const Point& rhs) const;
    Point operator-(const Point& rhs) const;
    int x, y;

    static int distSquared(const Point& p1, const Point& p2);

    friend std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        os << '(' << p.x << ',' << p.y << ')';
        return os;
    };

    friend std::istream& operator>>(std::istream& is, Point& p)
    {    is >> p.x >> p.y;
        return is;
    };
};






#endif //SVGPROJECTNEW_POINT_H
