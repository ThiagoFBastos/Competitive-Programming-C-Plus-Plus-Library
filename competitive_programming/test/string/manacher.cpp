#include <gtest/gtest.h>

#include "string/manacher.hpp"

TEST(Manacher, TestPalindromes)
{
    EXPECT_EQ(strings::manacher("abcbcba"), 7);
    EXPECT_EQ(strings::manacher("mississippi"), 7);
    EXPECT_EQ(strings::manacher("ababacaca"), 5);
    EXPECT_EQ(strings::manacher("aaaaa"), 5);
    EXPECT_EQ(strings::manacher("aybabtu"), 3);
    EXPECT_EQ(strings::manacher("ihpohpzoffel"), 2);
    EXPECT_EQ(strings::manacher("flexflexvpqxierullgcfckjqflexflex"), 3);
    EXPECT_EQ(strings::manacher("obsession"), 3);
    EXPECT_EQ(strings::manacher("abcxcbaxcba"), 7);
    EXPECT_EQ(strings::manacher("aaccaabbaaccaaccaabbaaccaa"), 26);
    EXPECT_EQ(strings::manacher("a"), 1);
    EXPECT_EQ(strings::manacher("abb"), 2);
    EXPECT_EQ(strings::manacher("aaaaaaaaaa"), 10);
}