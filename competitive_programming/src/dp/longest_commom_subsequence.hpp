#pragma once

#include <vector>
#include <algorithm>
#include <concepts>

namespace dp {

/**
 * @brief Find the longest commom sugsequence (LCS) between two vectors
 */
template<typename T>
requires std::equality_comparable<T> && std::copy_constructible<T>
inline std::vector<T> longest_commom_subsequence(const std::vector<T>& first, 
                                                 const std::vector<T>& second)
{
    constexpr int INF = 1e9;
    const int n = static_cast<int>(first.size());
	const int m = static_cast<int>(second.size());
	
    std::vector<T> sequence;
    std::vector<std::vector<int>> dp(n + 2, std::vector<int>(m + 2, INF));
 
	dp[n][m] = 0;
 
	for(int i = n; i >= 0; --i) 
    {
		for(int j = m ; j >= 0; --j) 
        {
			if(i < n && j < m && first[i] == second[j]) 
                dp[i][j] = 1 + dp[i + 1][j + 1];

			dp[i][j] = std::max({dp[i][j], dp[i + 1][j], dp[i][j + 1]});
		}
	}
 
	int target = dp[0][0], i {}, j {};
 
	while(i < n && j < m)
    {
		if(first[i] == second[j] && dp[i][j] == target)
        {
			sequence.push_back(first[i]);
			++i, ++j, --target;
		}
        else if(dp[i + 1][j] == target) ++i;
		else if(dp[i][j + 1] == target) ++j;
	}

    return sequence;
}

}
