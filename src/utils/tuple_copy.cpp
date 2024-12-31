#include "tuple.h"
#include <cmath>

Tuple::Tuple(float x, float y, float z, float w)
  : x_(x), y_(y), z_(z), w_(w) {}

Tuple Tuple::Point(float x, float y, float z)
{
  return Tuple(x, y, z, 1.0f);
}

Tuple Tuple::Vector(float x, float y, float z)
{
  return Tuple(x, y, z, 0.0f);
}

Tuple Tuple::operator-() const
{
  return Tuple(-x_, -y_, -z_, -w_);
}

Tuple operator+(const Tuple& rhs)
{
  return Tuple(x_ + rhs.getX(), y_ + rhs.getY(), z_ + rhs.getZ(), w_ + rhs.getW());
}

Tuple operator-(const Tuple& rhs)
{
  return Tuple(x_ - rhs.getX(), y_ - rhs.getY(), z_ - rhs.getZ(), w_ - rhs.getW());
}

Tuple operator*(float scalar)
{
  return Tuple(x_ * scalar, y_ * scalar, z_ * scalar, w_ * scalar);
}

Tuple operator/(float scalar)
{
  return Tuple(x_ / scalar, y_ / scalar, z_ / scalar, w_ / scalar);
}

bool Tuple::isEqual(const Tuple& rhs, double epsilon) const
{
  return std::fabs(x_ - rhs.x_) < epsilon &&
  std::fabs(y_ - rhs.y_) < epsilon &&
  std::fabs(z_ - rhs.z_) < epsilon &&
  std::fabs(w_ - rhs.w_) < epsilon;
}

float Tuple::magnitude() const
{
  return sqrt(x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_);
}

Tuple Tuple::normalize() const
{
  // float mag = magnitude();
  return Tuple(x_ / magnitude(),
               y_ / magnitude(),
               z_ / magnitude(),
               w_ / magnitude());
}

float Tuple::dot(const Tuple& rhs) const
{
  return (x_ * rhs.getX() +
          y_ * rhs.getY() +
          z_ * rhs.getZ() +
          w_ * rhs.getW());
}

Tuple Tuple::cross(const Tuple& rhs) const
{
  return Tuple::Vector(y_ * rhs.getZ() - z_ * rhs.getY(),
                       z_ * rhs.getX() - x_ * rhs.getZ(),
                       x_ * rhs.getY() - y_ * rhs.getX());
}

