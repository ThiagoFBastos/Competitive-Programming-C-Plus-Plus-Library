#include <gtest/gtest.h>

#include <string>

#include "dp/longest_commom_subsequence.hpp"

TEST(LCS, OnlyOneElement)
{
    const std::vector<int> first {1};
    const std::vector<int> second {1};
    const std::vector<int> expected {1};

    const auto lcs = dp::longest_commom_subsequence(first, second);

    EXPECT_EQ(lcs, expected);
}

TEST(LCS, DifferentElements)
{
    const std::vector<int> first {1};
    const std::vector<int> second {2};
    const std::vector<int> expected {};

    const auto lcs = dp::longest_commom_subsequence(first, second);

    EXPECT_EQ(lcs, expected);
}

TEST(LCS, ManyEqualElements)
{
    const std::vector<int> first {
         5, 5, 3, 5, 5, 2, 3, 4,
         3, 3, 4, 2, 3, 1, 4, 4,
         1, 5, 3, 4, 4, 3, 1, 3,
         5, 1, 4, 2, 2, 3, 5, 4,
         5, 3, 2, 5, 1, 5, 5, 5,
         1, 1, 4, 5, 1, 1, 2, 2,
         1, 3
    };

    const std::vector<int> second {
         2, 4, 5, 3, 1, 5, 3, 4,
         5, 2, 5, 1, 5, 3, 2, 5,
         2, 5, 5, 5, 2, 1, 4, 5,
         4, 1, 5, 4, 5, 3, 5, 5,
         3, 3, 1, 2, 1, 2, 3, 1,
         2, 4, 5, 3, 1, 5, 2, 4,
         3, 5
    };

    const std::vector<int> expected {
        2, 4, 3, 1, 5, 3, 4, 5, 2,
        5, 5, 3, 2, 5, 5, 5, 5, 1,
        1, 4, 5, 1, 1, 2, 2, 1, 3 
    };

    const auto lcs = dp::longest_commom_subsequence(first, second);

    EXPECT_EQ(lcs, expected);
}

TEST(LCS, AllAreEquals)
{
    constexpr std::size_t length = 100;
    const std::vector<char> first(length, 'A');
    const std::vector<char> second(length, 'A');
    const std::vector<char> expected(length, 'A');

    const auto lcs = dp::longest_commom_subsequence(first, second);

    EXPECT_EQ(lcs, expected);
}

TEST(LCS, EqualStrings)
{
    const std::vector<std::string> first {"xxx"};
    const std::vector<std::string> second {"xxx"};
    const std::vector<std::string> expected {"xxx"};

    const auto lcs = dp::longest_commom_subsequence(first, second);

    EXPECT_EQ(lcs, expected);
}
