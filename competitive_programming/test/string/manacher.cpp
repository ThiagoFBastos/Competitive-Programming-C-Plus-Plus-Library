#include <gtest/gtest.h>

#include "string/manacher.hpp"

TEST(Manacher, TestPalindromes)
{
    EXPECT_EQ(string::manacher("abcbcba"), 7);
    EXPECT_EQ(string::manacher("mississippi"), 7);
    EXPECT_EQ(string::manacher("ababacaca"), 5);
    EXPECT_EQ(string::manacher("aaaaa"), 5);
    EXPECT_EQ(string::manacher("aybabtu"), 3);
    EXPECT_EQ(string::manacher("ihpohpzoffel"), 2);
    EXPECT_EQ(string::manacher("flexflexvpqxierullgcfckjqflexflex"), 3);
    EXPECT_EQ(string::manacher("obsession"), 3);
    EXPECT_EQ(string::manacher("abcxcbaxcba"), 7);
    EXPECT_EQ(string::manacher("aaccaabbaaccaaccaabbaaccaa"), 26);
    EXPECT_EQ(string::manacher("a"), 1);
    EXPECT_EQ(string::manacher("abb"), 2);
    EXPECT_EQ(string::manacher("aaaaaaaaaa"), 10);
}