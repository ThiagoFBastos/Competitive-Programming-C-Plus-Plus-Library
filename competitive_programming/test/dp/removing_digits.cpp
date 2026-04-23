#include <gtest/gtest.h>

#include "dp/removing_digits.hpp"

using namespace dp;

TEST(RemovingDigits, TestPairs)
{
    EXPECT_EQ(removing_digits(27), 5);
    EXPECT_EQ(removing_digits(4), 1);
    EXPECT_EQ(removing_digits(17), 3);
    EXPECT_EQ(removing_digits(35), 7);
    EXPECT_EQ(removing_digits(167), 29);
    EXPECT_EQ(removing_digits(4434), 687);
    EXPECT_EQ(removing_digits(9722), 1381);
    EXPECT_EQ(removing_digits(37882), 5406);
    EXPECT_EQ(removing_digits(103330), 13867);
    EXPECT_EQ(removing_digits(562167), 75527);
    EXPECT_EQ(removing_digits(991919), 127308);
    EXPECT_EQ(removing_digits(999993), 128206);
    EXPECT_EQ(removing_digits(999999), 128206);
    EXPECT_EQ(removing_digits(23456), 3364);
    EXPECT_EQ(removing_digits(1000000), 128207);
}

