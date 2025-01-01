#include "color.h"
#include <gtest/gtest.h>

TEST(ColorTest, Constructor)
{
  Color c(-0.5f, 0.4f, 1.7f);

  ASSERT_EQ(c.getRed(), -0.5f);
  ASSERT_EQ(c.getGreen(), 0.4f);
  ASSERT_EQ(c.getBlue(), 1.7f);
}
