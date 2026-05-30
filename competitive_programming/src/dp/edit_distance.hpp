#pragma once

#include <string>
#include <vector>
#include <algorithm>

namespace dp {

/**
 * @brief Calculate the edit distance between two strings
 */
inline unsigned edit_distance(const std::string& s, const std::string& t)
{
    constexpr unsigned INF = 1'000'000'000u;
    const auto n = s.size();
	const auto m = t.size();
	
	std::vector<std::vector<unsigned>> dp(n + 2, std::vector<unsigned>(m + 2, INF));

	dp[0][0] = 0;

	for(std::size_t i = 0; i <= n; ++i)
    {
		for(std::size_t j = 0; j <= m; ++j)
        {
			dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j] + (t[j] != s[i]));
			dp[i + 1][j] = std::min(dp[i + 1][j], 1 + dp[i][j]);
			dp[i][j + 1] = std::min(dp[i][j + 1], 1 + dp[i][j]);
		}
	}

	return dp[n][m];
}

}
