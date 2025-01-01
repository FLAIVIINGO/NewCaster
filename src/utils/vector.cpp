#include "vector.h"

Vector::Vector() : Tuple(0.0f, 0.0f, 0.0f, 0.0f) {}

Vector::Vector(float x, float y, float z) : Tuple(x, y, z, 0.0f) {};

Vector Vector::normalize() const
{
  return Vector(x / magnitude(), y / magnitude(), z / magnitude());
}

float Vector::dot(const Vector& rhs) const
{
  return x * rhs.x +
         y * rhs.y +
         z * rhs.z;
}

Vector Vector::cross(const Vector& rhs) const
{
  return Vector(y * rhs.z - z * rhs.y,
                z * rhs.x - x * rhs.z,
                x * rhs.y - y * rhs.x);
}

Vector Vector::operator-(const Vector& rhs) const
{
  return Vector(x - rhs.getX(), y - rhs.getY(), z - rhs.getZ());
}

Vector Vector::operator+(const Vector& rhs) const
{
  return Vector(x + rhs.getX(), y + rhs.getY(), z + rhs.getZ());
}
