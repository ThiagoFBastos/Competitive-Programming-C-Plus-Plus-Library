#include <gtest/gtest.h>

#include "math/mint.hpp"

#include <sstream>
#include <string>

using namespace math;

TEST(Mint, SumTest)
{
    constexpr int MOD = 1e9 + 7;
    const mint<MOD> num1 = 2ll * MOD + 1;
    const mint<MOD> num2 = 4ll * MOD + 3ll;
    const mint<MOD> expected = 4;

    const auto sum = num1 + num2;
    
    EXPECT_EQ(sum, expected);
}

TEST(Mint, SubtractTest)
{
    constexpr int MOD = 1e9 + 7;
    const mint<MOD> num1 = 10ll * MOD + 10ll;
    const mint<MOD> num2 = 12ll * MOD + 3ll;
    const mint<MOD> expected = 7;

    const auto sub = num1 - num2;
    
    EXPECT_EQ(sub, expected);
}

TEST(Mint, MultiplyTest)
{
    constexpr int MOD = 1e9 + 7;
    const mint<MOD> num1 = 8ll * MOD + 9ll;
    const mint<MOD> num2 = 2ll * MOD + 6ll;
    const mint<MOD> expected = 54;

    const auto mul = num1 * num2;
    
    EXPECT_EQ(mul, expected);
}

TEST(Mint, DivisionTest)
{
    constexpr int MOD = 1e9 + 7;
    const mint<MOD> num1 = 100ll * MOD + 32ll;
    const mint<MOD> num2 = 35ll * MOD + 4ll;
    const mint<MOD> expected = 8;

    const auto div = num1 / num2;
    
    EXPECT_EQ(div, expected);
}

TEST(Mint, SumAssignTest)
{
    constexpr int MOD = 1e9 + 7;
    mint<MOD> num1 = 2ll * MOD + 1;
    const mint<MOD> num2 = 4ll * MOD + 3ll;
    const mint<MOD> expected = 4;

    num1 += num2;
    
    EXPECT_EQ(num1, expected);
}

TEST(Mint, SubtractAssignTest)
{
    constexpr int MOD = 1e9 + 7;
    mint<MOD> num1 = -10ll * MOD + 10ll;
    const mint<MOD> num2 = 12ll * MOD + 3ll;
    const mint<MOD> expected = 7;

    num1 -= num2;
    
    EXPECT_EQ(num1, expected);
}

TEST(Mint, MultiplyAssignTest)
{
    constexpr int MOD = 1e9 + 7;
    mint<MOD> num1 = 8ll * MOD + 9ll;
    const mint<MOD> num2 = MOD + 6ll;
    const mint<MOD> expected = 54;

    num1 *= num2;
    
    EXPECT_EQ(num1, expected);
}

TEST(Mint, DivisionAssignTest)
{
    constexpr int MOD = 1e9 + 7;
    mint<MOD> num1 = 100ll * MOD + 32ll;
    const mint<MOD> num2 = -MOD + 4ll;
    const mint<MOD> expected = 8;

    num1 /= num2;
    
    EXPECT_EQ(num1, expected);
}

TEST(Mint, CompareDifferentsTest)
{
    constexpr int MOD = 1e9 + 7;
    const mint<MOD> num1 = 100ll * MOD + 32ll;
    const mint<MOD> num2 = 35ll * MOD + 4ll;

    EXPECT_NE(num1, num2);
}

TEST(Mint, PowTest)
{
    constexpr int MOD = 1e9 + 7;
    const mint<MOD> num = 2ll;
    const mint<MOD> expected = 16;

    const auto pow = num.pow(4);

    EXPECT_EQ(pow, expected);
}

TEST(Mint, BoolTest)
{
    constexpr int MOD = 1e9 + 7;
    const mint<MOD> num1 = -100ll * MOD + 2ll;
    const mint<MOD> num2 = -34ll * MOD;

    EXPECT_TRUE(num1);
    EXPECT_FALSE(num2);
}

TEST(Mint, ReadTest)
{
    constexpr int MOD = 1e9 + 7;
    std::stringstream ss;
    mint<MOD> num;
    const mint<MOD> expected = 5;

    ss << 10ll * MOD + 5;
    ss >> num;

    EXPECT_EQ(num, expected);
}

TEST(Mint, WriteTest)
{
    constexpr int MOD = 1e9 + 7;
    std::stringstream ss;
    const mint<MOD> num = -MOD + 5;
    const std::string expected = "5";

    ss << num;

    EXPECT_EQ(ss.str(), expected);
}

TEST(Mint, NegativeTest)
{
    constexpr int MOD = 1e9 + 7;
    const mint<MOD> num = MOD - 1;
    const mint<MOD> expected = 1;

    const auto result = -num;

    EXPECT_EQ(result, expected);
}

TEST(Mint, InverseTest)
{
    constexpr int MOD = 1e9 + 9;
    const mint<MOD> num = 2;
    const mint<MOD> expected = 1;

    const auto inverse = num.inv();

    EXPECT_EQ(inverse * num, expected);
}
