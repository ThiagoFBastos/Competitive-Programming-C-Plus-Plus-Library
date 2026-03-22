#include <gtest/gtest.h>

#include "dp/rectangle_cutting.hpp"

TEST(RectangleCutting, TestPairs)
{
    EXPECT_EQ(dp::rectangle_cutting(2u, 8u), 3u);
    EXPECT_EQ(dp::rectangle_cutting(4u, 4u), 0u);
    EXPECT_EQ(dp::rectangle_cutting(1u, 4u), 3u);
    EXPECT_EQ(dp::rectangle_cutting(5u, 8u), 4u);
    EXPECT_EQ(dp::rectangle_cutting(5u, 10u), 1u);
    EXPECT_EQ(dp::rectangle_cutting(404u, 288u), 10u);
    EXPECT_EQ(dp::rectangle_cutting(349u, 234u), 13u);
    EXPECT_EQ(dp::rectangle_cutting(2u, 8u), 3u);
    EXPECT_EQ(dp::rectangle_cutting(180u, 137u), 12u);
    EXPECT_EQ(dp::rectangle_cutting(201u, 348u), 10u);
    EXPECT_EQ(dp::rectangle_cutting(132u, 46u), 9u);
    EXPECT_EQ(dp::rectangle_cutting(1u, 500u), 499u);
    EXPECT_EQ(dp::rectangle_cutting(1u, 1u), 0u);
    EXPECT_EQ(dp::rectangle_cutting(500u, 500u), 0u);
}
