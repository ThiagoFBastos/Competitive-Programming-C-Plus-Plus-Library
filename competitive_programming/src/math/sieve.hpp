#pragma once

#include <vector>

namespace math {

/**
 * @brief Find all primes less or equal than n
 */
inline std::vector<int> sieve(int n)
{
    std::vector<bool> is_prime(n + 1, true);
    std::vector<int> primes;

    for(int p = 2; p * p <= n; ++p)
    {
        if(!is_prime[p])
            continue;

        for(int i = 2 * p; i <= n; i += p)
            is_prime[i] = false;
    }

    for(int p = 2; p <= n; ++p)
    {
        if(is_prime[p])
            primes.emplace_back(p);
    }

    return primes;
}

}