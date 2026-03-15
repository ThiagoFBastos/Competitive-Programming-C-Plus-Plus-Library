#pragma once

inline long long bin_exp(long long n, long long p, long long mod) 
{
	long long ans = 1;
	for(; p > 0; p >>= 1) 
    {
		if(p & 1) ans = ans * n % mod;
		n = n * n % mod;
	}
	return ans;
}