#include "point.h"
#include "vector.h"

Point::Point() : Tuple(0.0f, 0.0f, 0.0f, 1.0f) {}

Point::Point(float x, float y, float z) : Tuple(x, y, z, 1.0f) {}

Point Point::operator+(const Vector& rhs) const
{
  return Point(x + rhs.getX(), y + rhs.getY(), z + rhs.getZ());
}

Vector Point::operator-(const Point& rhs) const
{
  return Vector(x - rhs.getX(), y - rhs.getY(), z - rhs.getZ());
}

Point Point::operator-(const Vector& rhs) const
{
  return Point(x - rhs.getX(), y - rhs.getY(), z - rhs.getZ());
}
