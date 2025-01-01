#include "tuple.h"
#include "vector.h"
#include "point.h"

#include <iostream>

class Environment
{
  private:
    Vector g;
    Vector w;

  public:
    Environment(const Vector& gravity, const Vector& wind)
      : g(gravity), w(wind) {}

    Vector getG()
    {
      return g;
    }

    Vector getW()
    {
      return w;
    }
};

class Projectile
{
  private:
    Point p;
    Vector v;


  public:
  Projectile(const Point& position, const Vector& velocity)
    : p(position), v(velocity) {}

  Point getP()
  {
    return p;
  }

  Projectile tick(Environment& env) const
  {
    Point position = p + v;
    Vector velocity = v + env.getG() + env.getW();
    return Projectile(position, velocity);
  }
};


int main()
{ 
  Projectile p(Point(0.0f, 1.0f, 0.0f), Vector(1.0f, 1.0f, 0.0f));
  Environment e(Vector(0.0f, -0.1f, 0.0f), Vector(-0.01f, 0.0f, 0.0f));

  while(p.getP().getY() >= 0)
  {
    std::cout << p.getP().getX() << " " << p.getP().getY() << std::endl;
    p = p.tick(e); 
  }
   
  std::cout << p.getP().getX() << " " << p.getP().getY() << std::endl;
  return 0;
}

