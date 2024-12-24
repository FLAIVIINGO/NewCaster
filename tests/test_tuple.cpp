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
