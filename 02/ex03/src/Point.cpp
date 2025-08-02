#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float x, float y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point::~Point() {}

Point& Point::operator=(const Point& other) {
    if (this != &other)
    {
        //new car _x et _y sont const
        new (this) Point(other);
    }
    return *this;
}


Fixed Point::getX() const
{
  return _x;
}

Fixed Point::getY() const
{
  return _y;
}

