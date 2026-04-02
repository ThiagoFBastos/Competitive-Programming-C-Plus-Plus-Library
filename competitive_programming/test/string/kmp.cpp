#include <gtest/gtest.h>

#include "string/kmp.hpp"

TEST(KMP, Palindrome)
{
    const std::string word = "abcbcba";
    const std::vector<int> expected {0, 0, 0, 0, 0, 0, 1};

    const auto kmp = strings::kmp(word);

    EXPECT_EQ(kmp, expected);
}

TEST(KMP, Repeated)
{
    const std::string word = "abcabcabc";
    const std::vector<int> expected {0, 0, 0, 1, 2, 3, 4, 5, 6};

    const auto kmp = strings::kmp(word);

    EXPECT_EQ(kmp, expected);
}

TEST(KMP, NoPrefix)
{
    const std::string word = "abcdef";
    const std::vector<int> expected {0, 0, 0, 0, 0, 0};

    const auto kmp = strings::kmp(word);

    EXPECT_EQ(kmp, expected);
}

TEST(KMP, AllSame)
{
    const std::string word = "aaaaaa";
    const std::vector<int> expected {0, 1, 2, 3, 4, 5};

    const auto kmp = strings::kmp(word);

    EXPECT_EQ(kmp, expected);
}

TEST(KMP, Empty)
{
    const std::string word = "";
    const std::vector<int> expected {};

    const auto kmp = strings::kmp(word);

    EXPECT_EQ(kmp, expected);
}
