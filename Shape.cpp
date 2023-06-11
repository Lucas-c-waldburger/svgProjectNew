#include "Shape.h"

// RECTANGLE //


void Rectangle::draw() const
{
    std::cout << R"(<rect x=")" << position.x << R"(" y=")" << position.y << R"(" width=")" << width
              << R"(" height=")" << height << R"("/>)";
}


std::stringstream Rectangle::drawToSVG() const
{
    std::stringstream svgOut;
    svgOut << R"(<rect x=")" << position.x << R"(" y=")" << position.y << R"(" width=")" << width
           << R"(" height=")" << height << R"("/>)";
    return svgOut;
}

// if the distance between center of circle and closest point on rectangle
// is less than circle radius squared, then overlaps
bool Rectangle::overlaps(const Circle& c) const
{
    std::cout << "Rectangle overlaps(circle) called\n";
    Point rClosest = Point(std::min(std::max(c.center.x, position.x), position.x + width),
                           std::min(std::max(c.center.y, position.y), position.y + height));

    int distSq = Point::distSquared(c.center, rClosest);

    return (distSq < (c.radius * c.radius));
}

bool Rectangle::fits_in(const Rectangle& r) const
{
    std::cout << "Rectangle fits in called\n";
    return ((position.x + width) <= r.width && (position.y + height) <= r.height);
}


bool Rectangle::overlaps(const Rectangle& r) const
{
    std::cout << "Rectangle overlaps(rectangle) called\n";
    int r1Verts[4] = {position.x, position.y, position.x + width, position.y + height};
    int r2Verts[4] = {r.position.x, r.position.y, r.position.x + r.width, r.position.y + r.height};

    return (std::min(r1Verts[2], r2Verts[2]) > std::max(r1Verts[0], r2Verts[0])) &&
           (std::min(r1Verts[3], r2Verts[3]) > std::max(r1Verts[1], r2Verts[1]));
}

bool Rectangle::overlaps(const Shape &s) const {
    return s.overlaps(*this);
}

//bool Rectangle::overlaps(const Shape &s) const
//{
//    const char* rName = "Rectangle";
//    const char* cName = "Circle";
//
//    if (typeid(s).name() == rName)
//    {
//        return overlaps(s);
//    }
//}





// CIRCLE //


void Circle::draw() const
{
    std::cout << R"(<circle cx=")"  << center.x << R"(" cy=")" << center.y << R"(" r=")" << radius << R"("/>)";
}

std::stringstream Circle::drawToSVG() const
{
    std::stringstream svgOut;
    svgOut << R"(<circle cx=")" << center.x << R"(" cy=")" << center.y << R"(" r=")" << radius << R"("/>)";
    return svgOut;
}

bool Circle::fits_in(const Rectangle& r) const
{
    std::cout << "center y - radius: " << center.y - radius << '\n' << "r.height: " << r.height <<'\n';
    return ((center.x - radius) >= 0) && ((center.x + radius) <= r.width) &&
           ((center.y - radius) >= 0) && ((center.y + radius) <= r.height);
}

bool Circle::overlaps(const Rectangle& r) const
{
    return r.overlaps(*this);
}

bool Circle::overlaps(const Circle& c) const
{
    std::cout << "Circle overlaps(circle) called\n";
    int distSq = Point::distSquared(c.center, center);

    return (radius*radius) - (c.radius*c.radius) < distSq &&
           distSq < (radius*radius) + (c.radius*c.radius);
}

bool Circle::overlaps(const Shape &s) const {
    return s.overlaps(*this);
}