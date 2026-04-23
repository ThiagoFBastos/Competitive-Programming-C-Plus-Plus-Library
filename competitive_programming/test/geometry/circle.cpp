#include <gtest/gtest.h>

#include "geometry/circle.hpp"

TEST(Circle, CompileTest)
{
    geometry::point center(0, 0);
    geometry::circle c(center, 10);

    EXPECT_TRUE(true);
}