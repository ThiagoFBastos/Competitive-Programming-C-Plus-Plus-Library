#pragma once

#include <vector>
#include <algorithm>
#include <numeric>
#include <array>

namespace dp
{

/**
 * There is a list of n numbers and two players who move alternately. 
 * On each move, a player removes either the first or last number from the list, 
 * and their score increases by that number. Both players try to maximize their scores.
 * What is the maximum possible score for the first player when both players play optimally?
 * n <= 5000
 * -10^9 <= nums[i] <= 10^9
 * @param nums The list of numbers.
 * @return The maximum possible score for the first player.
 */
inline long long removal_game(const std::vector<int>& nums)
{
    const auto n = nums.size();
    const auto sum = std::accumulate(nums.begin(), nums.end(), 0LL);
    constexpr long long INF = 0x1000000000000LL;

    std::vector<std::array<long long, 2>> dp(n, {0LL, 0LL});

    std::size_t turn = ~n & 1;

    for(std::size_t i = 0; i < n; ++i)
        dp[i][turn] = nums[i];

    for(std::size_t len = n - 1; len > 0; --len)
    {
        turn ^= 1;

        std::size_t my = turn, your = turn ^ 1;

        for(std::size_t i = 0; i < len; ++i)
            dp[i][my] = -INF;

        for(std::size_t i = 0; i < len; ++i)
            dp[i][my] = std::max(dp[i][my], nums[i] - dp[i + 1][your]);

        for(std::size_t i = 0; i < len; ++i)
            dp[i][my] = std::max(dp[i][my], nums[i + n - len] - dp[i][your]);
    }

    return (sum + dp[0][0]) / 2;
}

}