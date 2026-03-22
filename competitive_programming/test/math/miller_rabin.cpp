#include <gtest/gtest.h>

#include "math/pollard_rho.hpp"

using namespace math::factorization;

TEST(MillerRabin, PrimeNumbers)
{
    EXPECT_TRUE(miller(994630109758387LL));
    EXPECT_TRUE(miller(2919561194821441LL));
    EXPECT_TRUE(miller(81694559667311363LL));
    EXPECT_TRUE(miller(232947367708668887LL));
    EXPECT_TRUE(miller(1892901047LL));
    EXPECT_TRUE(miller(68449LL));
    EXPECT_TRUE(miller(479LL));
}

TEST(MillerRabin, CompositeNumbers)
{
    EXPECT_FALSE(miller(37678891LL * 6194113LL));
    EXPECT_FALSE(miller(605575583LL * 259490821LL));
    EXPECT_FALSE(miller(93490679LL * 50129LL));
    EXPECT_FALSE(miller(938107LL * 71047663LL));
    EXPECT_FALSE(miller(4222397LL * 1217LL));
    EXPECT_FALSE(miller(109LL * 528480915983LL));
    EXPECT_FALSE(miller(678297446759431LL * 17LL));
}