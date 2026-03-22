#pragma once

#include <string>
#include <vector>
#include <algorithm>

namespace dp {

/**
 * @brief Calculate the edit distance between two strings
 */
inline int edit_distance(const std::string& s, const std::string& t)
{
    constexpr int INF = 1e9;
    std::size_t n = s.size(), m = t.size();
	std::vector<std::vector<int>> dp(n + 2);

	for(std::size_t k = 0; k <= n + 1; ++k)
        dp[k].assign(m + 2, INF);

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
