#include "tuple.h"
#include <gtest/gtest.h>

TEST(TupleTest, Constructor)
{
  Tuple t1(4.3f, -4.2f, 3.1f, 1.0f);
  EXPECT_FLOAT_EQ(t1.getX(), 4.3f);
  EXPECT_FLOAT_EQ(t1.getY(), -4.2f);
  EXPECT_FLOAT_EQ(t1.getZ(), 3.1f);
  EXPECT_FLOAT_EQ(t1.getW(), 1.0f);

  EXPECT_TRUE(t1.isPoint());

  Tuple t2(4.3f, -4.2f, 3.1f, 0.0f);
  EXPECT_FLOAT_EQ(t2.getX(), 4.3f);
  EXPECT_FLOAT_EQ(t2.getY(), -4.2f);
  EXPECT_FLOAT_EQ(t2.getZ(), 3.1f);
  EXPECT_FLOAT_EQ(t2.getW(), 0.0f);

  EXPECT_TRUE(t2.isVector());
}

TEST(TupleTest, FactoryMethods)
{
  Tuple point = Tuple::Point(4.0f, -4.0f, 3.0f);
  Tuple vector = Tuple::Vector(4.0f, -4.0f, 3.0f);

  EXPECT_TRUE(point.isPoint());
  EXPECT_FALSE(point.isVector());

  EXPECT_FALSE(vector.isPoint());
  EXPECT_TRUE(vector.isVector());
}

TEST(TupleTest, EqualityFunction)
{
  Tuple point1 = Tuple::Point(4.0f, -4.0f, 3.0f);
  Tuple point2 = Tuple::Point(4.0f, -4.0f, 3.0f);

  EXPECT_TRUE(point1.isEqual(point2, 1e-5));
}

TEST(TupleTest, AdditionOperator)
{
  Tuple a1 = Tuple::Point(3.0f, -2.0f, 5.0f);
  Tuple a2 = Tuple::Vector(-2.0f, 3.0f, 1.0f);
  Tuple result = a1 + a2;

  Tuple answer = Tuple::Point(1.0f, 1.0f, 6.0f);

  EXPECT_TRUE(result.isEqual(answer, 1e-5));
}

TEST(TupleTest, SubtractionOperatorPoints)
{
  Tuple p1 = Tuple::Point(3.0f, 2.0f, 1.0f);
  Tuple p2 = Tuple::Point(5.0f, 6.0f, 7.0f);
  Tuple result = p1 - p2;
  Tuple answer = Tuple::Vector(-2.0f, -4.0f, -6.0f);

  EXPECT_TRUE(result.isEqual(answer, 1e-5));
}

TEST(TupleTest, SubtractingOperatorVectorPoint)
{
  Tuple p = Tuple::Point(3.0f, 2.0f, 1.0f);
  Tuple v = Tuple::Vector(5.0f, 6.0f, 7.0f);
  Tuple result = p - v;
  Tuple answer = Tuple::Point(-2.0f, -4.0f, -6.0f);

  EXPECT_TRUE(result.isEqual(answer, 1e-5));
}

TEST(TupleTest, SubtractingOperatorVectors)
{
  Tuple v1 = Tuple::Vector(3.0f, 2.0f, 1.0f);
  Tuple v2 = Tuple::Vector(5.0f, 6.0f, 7.0f);
  Tuple result = v1 - v2;
  Tuple answer = Tuple::Vector(-2.0f, -4.0f, -6.0f);

  EXPECT_TRUE(result.isEqual(answer, 1e-5));
}

TEST(TupleTest, NegatingOperator)
{
  Tuple a = Tuple(1.0f, -2.0f, 3.0f, -4.0f);
  Tuple answer = Tuple(-1.0f, 2.0f, -3.0f, 4.0f);
  Tuple result = -a;

  EXPECT_TRUE(result.isEqual(answer, 1e-5));
}

TEST(TupleTest, ScalarMultiplicationOperator)
{
  Tuple a = Tuple(1.0f, -2.0f, 3.0f, -4.0f);
  Tuple answer = Tuple(3.5f, -7.0f, 10.5f, -14.0f);
  Tuple result = a * 3.5;

  EXPECT_TRUE(result.isEqual(answer, 1e-5));
}

TEST(TupleTest, Magnitude1)
{
  Tuple v = Tuple::Vector(1.0f, 0.0f, 0.0f);
  float result = v.magnitude();

  EXPECT_TRUE(result == 1.0f);
}

TEST(TupleTest, Magnitude2)
{
  Tuple v = Tuple::Vector(0.0f, 1.0f, 0.0f);
  float result = v.magnitude();

  EXPECT_TRUE(result == 1.0f);
}

TEST(TupleTest, Magnitude3)
{
  Tuple v = Tuple::Vector(0.0f, 0.0f, 1.0f);
  float result = v.magnitude();

  EXPECT_TRUE(result == 1.0f);
}

TEST(TupleTest, Magnitude4)
{
  Tuple v = Tuple::Vector(1.0f, 2.0f, 3.0f);
  float result = v.magnitude();
  float ans = sqrt(14);

  EXPECT_TRUE(result == ans);
}

TEST(TupleTest, Magnitude5)
{
  Tuple v = Tuple::Vector(-1.0f, -2.0f, -3.0f);
  float result = v.magnitude();
  float ans = sqrt(14);

  EXPECT_TRUE(result == ans);
}

TEST(TupleTest, DotProduct)
{
  Tuple a = Tuple::Vector(1.0f, 2.0f, 3.0f);
  Tuple b = Tuple::Vector(2.0f, 3.0f, 4.0f);
  float result = a.dot(b);

  EXPECT_TRUE(result = 20.0f);
}

TEST(TupleTest, CrossProduct)
{
  Tuple a = Tuple::Vector(1.0f, 2.0f, 3.0f);
  Tuple b = Tuple::Vector(2.0f, 3.0f, 4.0f);
  Tuple r1 = a.cross(b);
  Tuple r2 = b.cross(a);

  Tuple a1 = Tuple::Vector(-1.0f, 2.0f, -1.0f);
  Tuple a2 = Tuple::Vector(1.0f, -2.0f, 1.0f);

  EXPECT_TRUE(r1.isEqual(a1, 1e-5));
  EXPECT_TRUE(r2.isEqual(a2, 1e-5));
}
