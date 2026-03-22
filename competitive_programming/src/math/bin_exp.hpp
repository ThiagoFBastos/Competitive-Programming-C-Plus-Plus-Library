#pragma once

namespace math {

/**
 * @brief Calculate n^p % mod in O(log p)
 * @param n the base number
 * @param p the power
 * @param mod the modulo number
 */
inline long long bin_exp(long long n, long long p, long long mod) 
{
	long long ans = 1;

	n %= mod;

	for(; p > 0; p >>= 1) 
    {
		if(p & 1) ans = ans * n % mod;
		n = n * n % mod;
	}

	return ans;
}

}
