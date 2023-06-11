
#ifndef SVGPROJECTNEW_SHAPE_H
#define SVGPROJECTNEW_SHAPE_H

#include "Point.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

class Circle; // why forward declaration?
class Rectangle;

class Shape
{
public:
    virtual ~Shape() = default;
    virtual bool overlaps(const Shape& s) const = 0;
    virtual bool overlaps(const Circle& r) const = 0;
    virtual bool overlaps(const Rectangle& r) const = 0;
    virtual bool fits_in(const Rectangle& r) const = 0;
    virtual void draw() const = 0;
    virtual std::stringstream drawToSVG() const = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(): position(Point(0,0)), width(0), height(0) {}
    Rectangle(Point p, int w, int h) : position(p), width(w), height(h) {}

    ~Rectangle() override = default;
    bool overlaps(const Shape& s) const override;
    bool overlaps(const Circle& c) const override;
    bool overlaps(const Rectangle& r) const override;
    bool fits_in(const Rectangle& r) const override;
    void draw() const override;
    std::stringstream drawToSVG() const override;

    const Point position;    // position of the lower left corner
    const int width, height;
};

class Circle : public Shape
{
public:
    Circle(): center(Point(0,0)), radius(0) {}
    Circle(Point c, int r) : center(c), radius(r) {}

    ~Circle() override = default;
    bool overlaps(const Shape& s) const override;
    bool overlaps(const Circle& r) const override;
    bool overlaps(const Rectangle& r) const override;
    bool fits_in(const Rectangle& r) const override;
    void draw() const override;
    std::stringstream drawToSVG() const override;

    Point center;
    int radius;
};


#endif //SVGPROJECTNEW_SHAPE_H
