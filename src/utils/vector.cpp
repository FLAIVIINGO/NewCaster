#include "vector.h"

Vector::Vector() : Tuple(0.0f, 0.0f, 0.0f, 0.0f) {}

Vector::Vector(float x, float y, float z) : Tuple(x, y, z, 0.0f) {};

Vector Vector::operator-(const Vector& rhs) const
{
  return Vector(x - rhs.getX(), y - rhs.getY(), z - rhs.getZ());
}
