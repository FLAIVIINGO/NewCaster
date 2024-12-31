#ifndef TUPLE_H
#define TUPLE_H

#include <cmath>

class Tuple
{
  protected:
    float x, y, z, w;
  public:
    // Constructors
    Tuple();
    Tuple(float x, float y, float z, float w);

    // Getters
    float getX() const;
    float getY() const;
    float getZ() const;
    float getW() const;

    // Type checking
    bool isPoint() const;
    bool isVector() const;

    bool equals(const Tuple& other) const;
    float magnitude() const;

    friend Tuple operator+(const Tuple& lhs, const Tuple& rhs);
    Tuple operator*(const float scalar) const;
    Tuple operator/(const float scalar) const;
    Tuple operator-() const;

    // deconstructor
    ~Tuple() = default;

};

#endif // TUPLE_H
