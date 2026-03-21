#include <gtest/gtest.h>

#include "math/bin_exp.hpp"

TEST(FastExp, SmallModulo) {
    constexpr auto MOD = (long long)(1e9 + 7);

    auto val = math::bin_exp(2ll, 3ll, MOD);

    EXPECT_EQ(val, 8ll);
}