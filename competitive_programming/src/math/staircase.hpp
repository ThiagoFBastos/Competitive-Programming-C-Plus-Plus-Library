#pragma once

#include <vector>
#include <ranges>
#include <numeric>
#include <execution>

namespace math {

/**
 * @brief staircase nim game solution
 * @param coins the coins that will be used in the game
 */
inline bool staircase(const std::vector<int>& coins)
{
    const auto n = coins.size();

    auto view = std::views::iota(std::size_t {}, n) | std::views::filter([](auto idx) {
        return idx % 2 == 1;
    }) | std::views::transform([&coins](auto idx) {
        return coins[idx];
    });

    int result = std::reduce(std::execution::seq, std::ranges::begin(view), std::ranges::end(view), 0, [](auto lhs, auto rhs) {
        return  lhs ^ rhs;
    });

    return result != 0;
}
}
