#pragma once

#include <vector>
#include <algorithm>

namespace dp {

/**
 * @brief Given an w x h rectangle, your task is to cut it into squares. 
 * On each move you can select a rectangle and cut it into two rectangles 
 * in such a way that all side lengths remain integers.
 *  What is the minimum possible number of moves?
 */
inline unsigned rectangle_cutting(unsigned w, unsigned h) 
{
    constexpr unsigned INF = 1'000'000'000u;
    std::vector<std::vector<unsigned>> dp(w + 1, std::vector<unsigned>(h + 1, INF));

    for(unsigned i = 0; i <= w; ++i)
		for(unsigned j = 0; j <= h; ++j)
			dp[i][j] = INF;

    auto diagonal = std::min(w, h);

	for(unsigned i = 0; i <= diagonal; ++i)
		dp[i][i] = 0;

	for(unsigned k = 1; k <= w; ++k)
    {
		for(unsigned j = 1; j <= h; ++j)
        {
			for(unsigned i = 1; i <= k; ++i)
				dp[k][j] = std::min(dp[k][j], 1 + dp[k - i][j] + dp[i][j]);

			for(unsigned i = 1; i <= j; ++i)
				dp[k][j] = std::min(dp[k][j], 1 + dp[k][j - i] + dp[k][i]);
		}
	}
	
    return dp[w][h];
}

}
