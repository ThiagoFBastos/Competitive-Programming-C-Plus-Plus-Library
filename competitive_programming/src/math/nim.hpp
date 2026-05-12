#pragma once

#include <vector>
#include <numeric>

namespace math {

/**
 * @brief nim game solution
 * @param coins the coins that will be used in the game
 */
inline bool nim(const std::vector<int>& coins)
{
    int result = std::accumulate(coins.begin(), coins.end(), 0, [](auto lhs, auto rhs) {
        return  lhs ^ rhs;
    });

    return result != 0;
}
}
