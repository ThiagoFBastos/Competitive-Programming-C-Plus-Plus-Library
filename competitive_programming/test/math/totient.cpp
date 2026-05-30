#include <gtest/gtest.h>

#include "math/totient.hpp"

TEST(Totient, TestTotientPairs)
{
    EXPECT_EQ(math::totient(2), 1);
    EXPECT_EQ(math::totient(5), 4);
    EXPECT_EQ(math::totient(7), 6);
    EXPECT_EQ(math::totient(2 * 3), 2);
    EXPECT_EQ(math::totient(2 * 3 * 5), 8);
    EXPECT_EQ(math::totient(2 * 2), 2);
    EXPECT_EQ(math::totient(2 * 2 * 3 * 3), 12);
    EXPECT_EQ(math::totient(2 * 2 * 3 * 3 * 5), 48);
}