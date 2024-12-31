#include "tuple.h"
#include <iostream>
#include <vector>

int main()
{
  Tuple position = Tuple::Point(0.0f, 1.0f, 0.0f);
  Tuple velocity = Tuple::Vector(1.0f, 1.0f, 0.0f).normalize();
  Tuple gravity = Tuple::Vector(0.0f, -0.1f, 0.0f);
  Tuple wind = Tuple::Vector(-0.01f, 0.0f, 0.0f);

  std::vector<Tuple> path;
  while (position.getY() > 0)
  {
    path.push_back(position);
    position = position + velocity;
    std::cout << "x: " << position.getX() << " y: " << position.getY() << std::endl;
    velocity = velocity + gravity + wind;
  }

  return 0;
}
