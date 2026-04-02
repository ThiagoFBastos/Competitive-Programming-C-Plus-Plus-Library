#include <gtest/gtest.h>

#include "data_structures/fenwick_tree.hpp"
#include <algorithm>
#include <numeric>
#include <utility>
#include <limits>

TEST(FenwickTree, SumTest)
{
    constexpr std::size_t N = 10;

    auto ft = data_structures::make_fenwick_tree<int>(N, std::plus<int>(), 0);

    for(std::size_t i = 1; i <= N; ++i)
        ft.update(i, i);

    for(std::size_t i = 1; i <= N; ++i)
    {
        EXPECT_EQ(ft.query(i), i * (i + 1) / 2);

        for(std::size_t j = 1; j < i; ++j)
            EXPECT_EQ(ft.query(i) - ft.query(j - 1), (i + j) * (i - j + 1) / 2);
    }
}

TEST(FenwickTree, MaxPrefixTest)
{
    constexpr std::size_t N = 10;

    const auto max = [](const auto& lhs, const auto& rhs) {
        return std::max(lhs, rhs);
    };

    auto ft = data_structures::make_fenwick_tree<int>(N, max, std::numeric_limits<int>::min());

    for(std::size_t i = 1; i <= N; ++i)
        ft.update(i, i);

    for(std::size_t i = 1; i <= N; ++i)
        EXPECT_EQ(ft.query(i), static_cast<int>(i));
}