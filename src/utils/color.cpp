#include "color.h"

Color::Color() : red(0.0), green(0.0), blue(0.0) {}

Color::Color(float red, float green, float blue)
  : red(red), green(green), blue(blue) {}

float Color::getRed() const { return red; }
float Color::getGreen() const { return green; }
float Color::getBlue() const { return blue; }
