#include <gtest/gtest.h>

#include "math/sieve.hpp"
#include "math/pollard_rho.hpp"

#include <ranges>

using namespace math;

TEST(Sieve, PrimesTest)
{
    constexpr int N = 1303; // this number is prime

    auto primes = sieve(N);

    auto view = std::views::iota(2, N + 1) | std::views::filter([](int n) {
        return factorization::miller(n);
    });

    std::vector<int> numbers(std::ranges::begin(view), std::ranges::end(view));

    EXPECT_EQ(primes, numbers);
}