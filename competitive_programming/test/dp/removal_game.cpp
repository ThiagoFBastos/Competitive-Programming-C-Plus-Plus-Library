#include <gtest/gtest.h>

#include "dp/removal_game.hpp"

using namespace dp;

TEST(RemovalGame, TestPairs)
{
    EXPECT_EQ(removal_game({-5, 5, 9, -4, 10, -9, 0, 3, 2, -6}), 16);
    EXPECT_EQ(removal_game({0, -3, -9, -9, -3, 5, 6, 3, 8, 5}), 2);
    EXPECT_EQ(removal_game({-5, 5, -5, 6, -8, -9, -6, 3, 0, 2}), 7);
    EXPECT_EQ(removal_game({-7, 6, -8, -7, -10, -8, -7, 10, -6, -10}), -9);
    EXPECT_EQ(removal_game({-8, 4, 6, -2, 5, -4, -5, 9, 10, 1}), 13);
    EXPECT_EQ(removal_game({1, 2, 9}), 10);
    EXPECT_EQ(removal_game({5}), 5);
}