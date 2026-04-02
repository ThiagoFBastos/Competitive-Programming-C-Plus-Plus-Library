#include <gtest/gtest.h>

#include "data_structures/segment_tree.hpp"

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>
#include <numeric>
#include <limits>

using namespace data_structures;

struct SumTraits
{
    using value_type = int;

    static value_type merge(const value_type& lhs, const value_type& rhs)
    {
        return lhs + rhs;
    }

    static value_type neutral()
    {
        return 0;
    }
};

struct MinTraits
{
    using value_type = int;

    static value_type merge(const value_type& lhs, const value_type& rhs)
    {
        return std::min(lhs, rhs);
    }

    static value_type neutral()
    {
        return std::numeric_limits<int>::max();
    }
};

TEST(SegmentTree, SumTest)
{
    constexpr std::size_t N = 50;

    auto view = std::views::iota(1, 1 + static_cast<int>(N));

    std::vector<int> vec;
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

    vec.reserve(N);

    for(const auto& value : view)
        vec.push_back(value);

    std::shuffle(vec.begin(), vec.end(), rng);

    SegTree<SumTraits> st(vec);

    for(std::size_t i = 0; i < N; ++i)
    {
        for(std::size_t j = 0; j <= i; ++j)
        {
            auto sum = std::accumulate(vec.begin() + j, vec.begin() + i + 1, 0);

            EXPECT_EQ(st.query(j, i), sum);
        }
    }
}

TEST(SegmentTree, MinTest)
{
    constexpr std::size_t N = 50;

    auto view = std::views::iota(1, 1 + static_cast<int>(N));

    std::vector<int> vec;
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

    vec.reserve(N);

    for(const auto& value : view)
        vec.push_back(value);

    std::shuffle(vec.begin(), vec.end(), rng);

    SegTree<MinTraits> st(vec);

    for(std::size_t i = 0; i < N; ++i)
    {
        for(std::size_t j = 0; j <= i; ++j)
        {
            auto min = std::reduce(vec.begin() + j, vec.begin() + i + 1, std::numeric_limits<int>::max(), [](const auto& acc, const auto& value) {
                return std::min(acc, value);
            });

            EXPECT_EQ(st.query(j, i), min);
        }
    }
}