#include <gtest/gtest.h>

#include "math/sum_floor.hpp"

TEST(SumFloor, TestPairs)
{
    EXPECT_EQ(math::sum_floor(4LL, 10LL, 6LL, 3LL), 3LL);
    EXPECT_EQ(math::sum_floor(6LL, 5LL, 4LL, 3LL), 13LL);
    EXPECT_EQ(math::sum_floor(1LL, 1LL, 0LL, 0LL), 0LL);
    EXPECT_EQ(math::sum_floor(31415LL, 92653LL, 58979LL, 32384LL), 314095480LL);
    EXPECT_EQ(
        math::sum_floor(1000000000LL, 1000000000LL, 999999999LL, 999999999LL),
        499999999500000000LL
    );
}