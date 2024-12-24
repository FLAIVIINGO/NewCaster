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

Tuple operator+(const Tuple& lhs, const Tuple& rhs)
{
  return Tuple(lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY(), lhs.getZ() + rhs.getZ(), lhs.getW() + rhs.getW());
}

Tuple operator-(const Tuple& lhs, const Tuple& rhs)
{
  return Tuple(lhs.getX() - rhs.getX(), lhs.getY() - rhs.getY(), lhs.getZ() - rhs.getZ(), lhs.getW() - rhs.getW());
}

bool Tuple::isEqual(const Tuple& rhs, double epsilon) const
{
  return std::fabs(x_ - rhs.x_) < epsilon &&
  std::fabs(y_ - rhs.y_) < epsilon &&
  std::fabs(z_ - rhs.z_) < epsilon &&
  std::fabs(w_ - rhs.w_) < epsilon;
}

