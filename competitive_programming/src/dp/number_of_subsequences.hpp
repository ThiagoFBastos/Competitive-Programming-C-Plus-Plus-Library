#pragma once

#include <vector>
#include <unordered_map>

namespace dp {

/**
 * @brief Count the number of distinct subsequences
 */
inline int number_of_subsequences(const std::vector<int>& sequence, int MOD)
{
	const auto n = sequence.size();
	long long dp {};

	std::unordered_map<int, int> DP;

	DP.reserve(n);

	for(const int v : sequence) 
	{
		int count = (1 + dp - DP[v]) % MOD;
		dp = (dp + count) % MOD;
		DP[v] = (DP[v] + count) % MOD;
	}

	return (dp + MOD) % MOD;
}

}
