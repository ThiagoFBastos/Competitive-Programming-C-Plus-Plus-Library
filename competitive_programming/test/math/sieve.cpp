#include <gtest/gtest.h>

#include "math/sieve.hpp"
#include "math/pollard_rho.hpp"

#include <ranges>

using namespace math;

TEST(Siveve, PrimesTest)
{
    constexpr int N = 1000;

    auto primes = sieve(N);

    auto view = std::views::iota(2, N + 1) | std::views::filter([](int n) {
        return factorization::miller(n);
    });

    std::vector<int> numbers(std::ranges::begin(view), std::ranges::end(view));

    EXPECT_EQ(primes, numbers);
}