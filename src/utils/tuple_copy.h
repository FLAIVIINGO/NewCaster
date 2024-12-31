#ifndef RC_UTILS_TUPLE
#define RC_UTILS_TUPLE

#include <cmath>

class Tuple
{
  private:
    float x_, y_, z_, w_;
  public:
    Tuple() : x_(0.0f), y_(0.0f), z_(0.0f), w_(0.0f) {};

    Tuple(float x, float y, float z, float w);

    static Tuple Point(float x, float y, float z);

    static Tuple Vector(float x, float y, float z);

    float getX() const { return x_; }
    float getY() const { return y_; }
    float getZ() const { return z_; }
    float getW() const { return w_; }

    Tuple operator-() const;
    friend Tuple operator+(const Tuple& rhs);
    friend Tuple operator-(const Tuple& rhs);
    friend Tuple operator*(float scalar);
    friend Tuple operator/(float scalar);

    bool isPoint() const { return w_ == 1.0f; }
    bool isVector() const { return w_ == 0.0f; }
    bool isEqual(const Tuple& rhs, double epsilon) const;
    float magnitude() const;
    Tuple normalize() const;
    float dot(const Tuple& rhs) const;
    Tuple cross(const Tuple& rhs) const;

    // deconstructor
    ~Tuple() = default;

};

#endif // RC_UTILS_TUPLE
