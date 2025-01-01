#include "tuple.h"
#include "point.h"
#include "vector.h"
#include <gtest/gtest.h>

TEST(TupleTest, PointConstructor)
{
  Tuple a(4.3f, -4.2f, 3.1f, 1.0f);

  EXPECT_TRUE(a.isPoint());
  EXPECT_FALSE(a.isVector());
  EXPECT_EQ(a.getX(), 4.3f);
  EXPECT_EQ(a.getY(), -4.2f);
  EXPECT_EQ(a.getZ(), 3.1f);
  EXPECT_EQ(a.getW(), 1.0f);
}

TEST(TupleTest, VectorConstructor)
{
  Tuple a(4.3f, -4.2f, 3.1f, 0.0f);

  EXPECT_TRUE(a.isVector());
  EXPECT_FALSE(a.isPoint());
  EXPECT_EQ(a.getX(), 4.3f);
  EXPECT_EQ(a.getY(), -4.2f);
  EXPECT_EQ(a.getZ(), 3.1f);
  EXPECT_EQ(a.getW(), 0.0f);
}

TEST(TupleTest, Constructor)
{
  Point p(4.0f, -4.0f, 3.0f);
  Vector v(4.0f, -4.0f, 3.0f);  

  EXPECT_TRUE(p.isPoint());
  EXPECT_FALSE(p.isVector());
  EXPECT_EQ(p.getX(), 4.0f);
  EXPECT_EQ(p.getY(), -4.0f);
  EXPECT_EQ(p.getZ(), 3.0f);
  EXPECT_EQ(p.getW(), 1.0f);

  EXPECT_TRUE(v.isVector());
  EXPECT_FALSE(v.isPoint());
  EXPECT_EQ(v.getX(), 4.0f);
  EXPECT_EQ(v.getY(), -4.0f);
  EXPECT_EQ(v.getZ(), 3.0f);
  EXPECT_EQ(v.getW(), 0.0f);
}

TEST(TupleTest, TupleAddition)
{
  Tuple a1(3.0f, -2.0f, 5.0f, 1.0f);
  Tuple a2(-2.0f, 3.0f, 1.0f, 0.0f);
  Tuple a3 = a1 + a2;

  EXPECT_EQ(a3.getX(), 1.0f);
  EXPECT_EQ(a3.getY(), 1.0f);
  EXPECT_EQ(a3.getZ(), 6.0f);
  EXPECT_EQ(a3.getW(), 1.0f);
}

TEST(TupleTest, PointSubtraction)
{
  Point p1(3.0f, 2.0f, 1.0f);
  Point p2(5.0f, 6.0f, 7.0f);
  
  EXPECT_TRUE((p1 - p2).equals(Vector(-2.0f, -4.0f, -6.0f)));
}

TEST(TupleTest, PointVectorSubtraction)
{
  Point p(3.0f, 2.0f, 1.0f);
  Vector v(5.0f, 6.0f, 7.0f);

  EXPECT_TRUE((p - v).equals(Point(-2.0f, -4.0f, -6.0f)));
}

TEST(TupleTest, VectorSubtraction)
{
  Vector v1(3.0f, 2.0f, 1.0f);
  Vector v2(5.0f, 6.0f, 7.0f);

  EXPECT_TRUE((v1 - v2).equals(Vector(-2.0f, -4.0f, -6.0f)));
}

TEST(TupleTest, NegateTuple)
{
  Tuple a(1.0f, -2.0f, 3.0f, -4.0f);

  Tuple b = -a;

  EXPECT_TRUE(b.equals(Tuple(-1.0f, 2.0f, -3.0f, 4.0f)));
}

TEST(TupleTest, ScalarMultiplication)
{
  Tuple a(1.0f, -2.0f, 3.0f, -4.0f);
  Tuple b = a * 3.5;

  EXPECT_TRUE(b.equals(Tuple(3.5f, -7.0f, 10.5f, -14.0f)));
}

TEST(TupleTest, ScalarDivision)
{
  Tuple a(1.0f, -2.0f, 3.0f, -4.0f);
  Tuple b = a / 2.0f;
  
  EXPECT_TRUE(b.equals(Tuple(0.5f, -1.0f, 1.5f, -2.0f)));
}

TEST(TupleTest, Magnitude)
{
  Vector v1(0.0f, 1.0f, 0.0f);
  ASSERT_EQ(v1.magnitude(), 1.0f);
  Vector v2(0.0f, 0.0f, 1.0f);
  ASSERT_EQ(v2.magnitude(), 1.0f);
}

TEST(TupleTest, Normalize)
{
  Vector v(4.0f, 0.0f, 0.0f);
  Vector a = v.normalize();
  EXPECT_TRUE(a.equals(Tuple(1.0f, 0.0f, 0.0f, 0.0f)));
}

TEST(TupleTest, DotProduct)
{
  Vector a(1.0f, 2.0f, 3.0f);
  Vector b(2.0f, 3.0f, 4.0f);
  ASSERT_EQ(a.dot(b), 20.0f);
}

TEST(TupleTest, CrossProduct)
{
  Vector a(1.0f, 2.0f, 3.0f);
  Vector b(2.0f, 3.0f, 4.0f);
  Vector c = a.cross(b);
  Vector d = b.cross(a);
  EXPECT_TRUE(c.equals(Tuple(-1.0f, 2.0f, -1.0f, 0.0f)));
  EXPECT_TRUE(d.equals(Tuple(1.0f, -2.0f, 1.0f, 0.0f)));
}
