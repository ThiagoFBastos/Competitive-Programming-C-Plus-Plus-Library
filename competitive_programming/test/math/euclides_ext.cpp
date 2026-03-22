#include <gtest/gtest.h>

#include "math/euclides_ext.hpp"

#include <chrono>
#include <random>
#include <algorithm>

TEST(EuclidesEXt, RandomTests)
{
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    constexpr int MAXN = 1'000'000;

    auto randrange = [&rng](int l, int r) {
        return rng() % (r - l + 1) + l;
    };

    for(int i = 0; i < 50; ++i)
    {
        const long long a = randrange(1, MAXN), b = randrange(1, MAXN);
        long long x, y;
        const long long expectedGcd = std::gcd(a, b);
        
        const auto gcd = math::euclides(a, b, x, y);

        EXPECT_EQ(gcd, expectedGcd);
        EXPECT_EQ(a * x + b * y, expectedGcd);
    }
}
