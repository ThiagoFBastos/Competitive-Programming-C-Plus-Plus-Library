#include <gtest/gtest.h>

#include <random>
#include <chrono>
#include <limits>

#include "bitwise/maximum_xor_subset.hpp"

using namespace bitset;

TEST(MaximumXorSubset, MaximumXorSubsetTest)
{
    EXPECT_EQ(maximum_xor_subset({1, 6, 12, 6}), 13);
    EXPECT_EQ(maximum_xor_subset({48, 33, 96, 77, 67, 59, 35, 15, 14, 86}), 127);
    EXPECT_EQ(maximum_xor_subset({5, 1, 2}), 7);
    EXPECT_EQ(maximum_xor_subset({7, 8, 1, 2, 16, 32}), 63);
}

TEST(MaximumXorSubset, RandomTest)
{
    constexpr std::size_t N = 10;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<value_type> uid(0, std::numeric_limits<value_type>::max());

    std::vector<value_type> arr(N);

    value_type expected_result {};

    for(std::size_t i = 0; i < N; ++i)
        arr[i] = uid(gen);

    for(std::size_t i = 0; i < (1 << N); ++i)
    {
        value_type current_xor {};

        for(std::size_t j = 0; j < N; ++j)
        {
            if((i >> j) & 1)
                current_xor ^= arr[j];
        }

        expected_result = std::max(expected_result, current_xor);
    }

    EXPECT_EQ(maximum_xor_subset(std::move(arr)), expected_result);
}