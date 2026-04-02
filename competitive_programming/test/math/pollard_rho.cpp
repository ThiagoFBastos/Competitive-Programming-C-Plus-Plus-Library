#include <gtest/gtest.h>

#include "math/pollard_rho.hpp"

using namespace math::factorization;

TEST(PollardRho, FactorizationTest)
{
    constexpr long long n = 4128133LL * 33013LL * 17LL * 17LL;
    const std::vector<std::pair<long long, int>> expected = {
        {17LL, 2},
        {33013LL, 1},
        {4128133LL, 1}
    };

    auto factors = factorize(n);

    std::sort(factors.begin(), factors.end());
    
    EXPECT_EQ(factors, expected);
}

TEST(PollardRho, LargeFactorizationTest)
{
    constexpr __int128 n = (__int128)2879704699LL * (__int128)7000952377LL;

    const std::vector<std::pair<__int128, int>> expected = {
        {(__int128)2879704699LL, 1},
        {(__int128)7000952377LL, 1}
    };

    auto factors = factorize(n);

    std::sort(factors.begin(), factors.end());
    
    EXPECT_EQ(factors, expected);
}