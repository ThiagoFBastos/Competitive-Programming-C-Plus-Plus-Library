#include <gtest/gtest.h>

#include "math/bin_exp.hpp"

TEST(BinExp, ZeroRaisedToZero)
{
    constexpr auto MOD = (long long)(1e9 + 7);

    auto result = math::bin_exp(0ll, 0ll, MOD);

    EXPECT_EQ(result, 1ll);
}

TEST(BinExp, ZeroRaisedToOne)
{
    constexpr auto MOD = (long long)(1e9 + 7);

    auto result = math::bin_exp(0ll, 1ll, MOD);

    EXPECT_EQ(result, 0ll);
}

TEST(BinExp, TwoRaisedToThree)
{
    constexpr auto MOD = (long long)(1e9 + 7);

    auto result = math::bin_exp(2ll, 3ll, MOD);

    EXPECT_EQ(result, 8ll);
}


TEST(BinExp, InversionOfTwo)
{
    constexpr auto MOD = (long long)(1e9 + 9);

    auto result = math::bin_exp(2ll, (MOD - 1) / 2, MOD);

    EXPECT_EQ(result, 1ll);
}

TEST(BinExp, MultipleOfTwo)
{
    auto result = math::bin_exp(2ll, 1ll << 60, 2ll);

    EXPECT_EQ(result, 0ll);
}

TEST(BinExp, BigNumbers)
{
    constexpr auto MOD = (long long)(1e9 + 7);

    EXPECT_EQ(math::bin_exp(692427692ll, 536870911ll, MOD), 940305728ll);
    EXPECT_EQ(math::bin_exp(252480658ll, 536870911ll, MOD), 707431813ll);   
    EXPECT_EQ(math::bin_exp(129612095ll, 411099530ll, MOD), 276067146ll);
    EXPECT_EQ(math::bin_exp(241615980ll, 487174929ll, MOD), 838400234ll);
    EXPECT_EQ(math::bin_exp(60862511ll, 511830781ll, MOD), 148093882ll);
}

TEST(BinExp, InverseModular)
{
    constexpr auto MOD = (long long)(37);

    auto inverse = math::bin_exp(9, MOD - 2, MOD);

    EXPECT_EQ(9 * inverse % MOD, 1);
}
