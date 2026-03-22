#include <gtest/gtest.h>

#include "dp/number_of_subsequences.hpp"

TEST(NumberOfSubsequences, EmptySequenceTest)
{
    const std::vector<int> sequence {};
    constexpr int expected {};
    constexpr int MOD = 998244353;

    const auto count = dp::number_of_subsequences(sequence, MOD);

    EXPECT_EQ(count, expected);
}

TEST(NumberOfSubsequences, ZeroesAndOnesTest)
{
    const std::vector<int> sequence {0, 0, 0, 1, 1};
    constexpr int expected = 11;
    constexpr int MOD = 998244353;

    const auto count = dp::number_of_subsequences(sequence, MOD);

    EXPECT_EQ(count, expected);
}

TEST(NumberOfSubsequences, SampleTest)
{
    const std::vector<int> sequence {9, 9, 8, 2, 4, 4, 3, 5, 3};
    constexpr int expected = 251;
    constexpr int MOD = 998244353;

    const auto count = dp::number_of_subsequences(sequence, MOD);

    EXPECT_EQ(count, expected);
}
