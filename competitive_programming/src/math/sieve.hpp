#pragma once

#include <vector>
#include <ranges>

namespace math {

/**
 * @brief Find all primes less or equal than n
 */
inline std::vector<int> sieve(int n)
{
    std::vector<bool> is_prime(n + 1, true);

    for(int p = 2; p * p <= n; ++p)
    {
        if(!is_prime[p])
            continue;

        for(int i = p * p; i <= n; i += p)
            is_prime[i] = false;
    }

    std::vector<int> primes;

    auto filtered = std::views::iota(2, n + 1) | std::views::filter([&](int x) { return static_cast<bool>(is_prime[x]);});

    std::ranges::copy(filtered, std::back_inserter(primes));

    return primes;
}

}