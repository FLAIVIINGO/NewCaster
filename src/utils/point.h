#ifndef POINT_H
#define POINT_H

#include "tuple.h"
#include "vector.h"

class Point : public Tuple 
{
  public:
    Point();
    Point(float x, float y, float z);

    Point operator+(const Vector& rhs) const;
    Vector operator-(const Point& rhs) const;
    Point operator-(const Vector& rhs) const;
};

#endif // POINT_H
