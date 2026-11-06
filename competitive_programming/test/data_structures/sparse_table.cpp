#include <gtest/gtest.h>

#include "data_structures/sparse_table.hpp"

#include <random>
#include <chrono>
#include <ranges>
#include <utility>
#include <numeric>


TEST(SparseTable, RMQTest)
{
    constexpr auto INF = std::numeric_limits<long long>::max();
    constexpr std::size_t N = 50;

    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<long long> uid(0, INF);

    const auto view = std::views::iota(std::size_t{}, N) | std::views::transform([&uid, &rng](auto) {
        return uid(rng);
    });

    std::vector<long long> vec;

    std::ranges::copy(view, std::back_inserter(vec));

    const auto sp = data_structures::make_sparse_table(std::ranges::begin(vec), std::ranges::end(vec), std::ranges::min);

    for(std::size_t l = 0; l < N; ++l)
    {
        auto min = std::numeric_limits<long long>::max();

        for(std::size_t r = l; r < N; ++r)
        {
            min = std::min(min, vec[r]);
            EXPECT_EQ(sp.query(l, r), min);
        }
    }
}

TEST(SparseTable, LogQueryTest)
{
    constexpr int MAXN = 1'000'000;
    constexpr std::size_t N = 50;

    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> uid(0, MAXN);

    const auto view = std::views::iota(std::size_t{}, N) | std::views::transform([&uid, &rng](auto) {
        return uid(rng);
    });

    std::vector<int> vec;

    std::ranges::copy(view, std::back_inserter(vec));

    const auto sp = data_structures::make_sparse_table(std::ranges::begin(vec), std::ranges::end(vec), std::plus<int>());

    for(std::size_t l = 0; l < N; ++l)
    {
        int sum {};

        for(std::size_t r = l; r < N; ++r)
        {
            sum += vec[r];
            EXPECT_EQ(sp.query(0, l, r), sum);
        }
    }
}