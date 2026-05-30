#include <gtest/gtest.h>

#include "string/z_function.hpp"

TEST(ZFunction, Palindrome)
{
    const std::string word = "abcbcba";
    const std::vector<int> expected {0, 0, 0, 0, 0, 0, 1};

    const auto z = string::z_function(word);

    EXPECT_EQ(z, expected);
}

TEST(ZFunction, AllZeroes)
{
    const std::string word = "mississippi";
    const std::vector<int> expected {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    const auto z = string::z_function(word);

    EXPECT_EQ(z, expected);
}

TEST(ZFunction, SomeEqualSuffixies)
{
    const std::string word = "ababacaca";
    const std::vector<int> expected {0, 0, 3, 0, 1, 0, 1, 0, 1};

    const auto z = string::z_function(word);

    EXPECT_EQ(z, expected);
}

TEST(ZFunction, AllEqual)
{
    const std::string word = "aaaaa";
    const std::vector<int> expected {0, 4, 3, 2, 1};

    const auto z = string::z_function(word);

    EXPECT_EQ(z, expected);    
}
