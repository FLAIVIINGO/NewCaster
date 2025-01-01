#ifndef VECTOR_H
#define VECTOR_H

#include "tuple.h"

class Vector : public Tuple
{
  public:
    Vector();
    Vector(float x, float y, float z);

    Vector normalize() const;
    float dot(const Vector& rhs) const;
    Vector cross(const Vector& rhs) const;

    Vector operator-(const Vector& rhs) const;
    Vector operator+(const Vector& rhs) const;
};

#endif // VECTOR_H
