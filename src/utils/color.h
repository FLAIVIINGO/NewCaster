#ifndef COLOR_H
#define COLOR_H


class Color
{
  private:
    float red, green, blue;

  public:
    Color();
    Color(float red, float green , float blue);

    // Getters
    float getRed() const;
    float getGreen() const;
    float getBlue() const;
};

#endif // COLOR_H
