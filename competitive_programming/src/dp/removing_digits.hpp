#pragma once

#include <vector>
#include <algorithm>

namespace dp
{

/**
 * Given an integer n, return the minimum number of steps to reduce it to zero.
 * In one step, you can remove any digit from n and subtract it from n.
 */
inline int removing_digits(int n)
{
   std::vector<int> dp(n + 1);
 
	dp[0] = 0;
 
	for(int k = 1; k <= n; ++k) 
    {
		int digit = 0;
 
		for(int N = k; N > 0; N /= 10)
			digit = std::max(N % 10, digit);

		dp[k] = 1 + dp[k - digit];
	}

    return dp[n];
}

}