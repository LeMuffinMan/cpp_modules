#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point 
{
  public: 
    Point();
    Point(float x, float y);
    Point(const Point& other);
    ~Point();

    Point& operator=(const Point& other);

    Fixed getX() const;
    Fixed getY() const;
  private: 
    Fixed const _x; 
    Fixed const _y; 

};

#endif 
