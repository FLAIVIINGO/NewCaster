#include "tuple.h"
#include <cmath>

const float EPSILON = 0.00001;

Tuple::Tuple() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

Tuple::Tuple(float x, float y, float z, float w)
  : x(x), y(y), z(z), w(w) {}

float Tuple::getX() const { return x; }
float Tuple::getY() const { return y; }
float Tuple::getZ() const { return z; }
float Tuple::getW() const { return w; }

bool Tuple::isPoint() const { return w == 1.0f; }
bool Tuple::isVector() const { return w == 0.0f; }

bool Tuple::equals(const Tuple& other) const
{
  return (std::abs(x - other.x) < EPSILON &&
          std::abs(y - other.y) < EPSILON &&
          std::abs(z - other.z) < EPSILON &&
          std::abs(w - other.w) < EPSILON);
}

float Tuple::magnitude() const
{
  return std::sqrt(x*x+y*y+z*z+w*w);
}

Tuple operator+(const Tuple& lhs, const Tuple& rhs)
{
  return Tuple(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

Tuple Tuple::operator*(const float scalar) const
{
  return Tuple(x * scalar, y * scalar, z * scalar, w * scalar);
}

Tuple Tuple::operator/(const float scalar) const
{
  return Tuple(x / scalar, y / scalar, z / scalar, w / scalar);
}

Tuple Tuple::operator-() const
{
  return Tuple(-x, -y, -z, -w);
}
