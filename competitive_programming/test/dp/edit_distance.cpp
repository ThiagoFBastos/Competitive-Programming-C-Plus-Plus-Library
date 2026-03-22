#include <gtest/gtest.h>

#include "dp/edit_distance.hpp"

TEST(EditDistance, SimpleTest) 
{
    const std::string s = "LOVE";
    const std::string t = "MOVIE";
    const unsigned expected = 2u;

    const auto edit = dp::edit_distance(s, t);

    EXPECT_EQ(edit, expected);
}

TEST(EditDistance, NoOperations) 
{
    const std::string s = "A";
    const std::string t = "A";
    const unsigned expected = 0u;

    const auto edit = dp::edit_distance(s, t);

    EXPECT_EQ(edit, expected);
}

TEST(EditDistance, OneOperation)
{
    const std::string s = "A";
    const std::string t = "B";
    const unsigned expected = 1u;

    const auto edit = dp::edit_distance(s, t);

    EXPECT_EQ(edit, expected);
}

TEST(EditDistance, ManyOperations)
{
    const std::string s = "TWXFUABGBNLTBFNSUVQW";
    const std::string t = "GPNJILFXJUIZPLTVUIB";
    const unsigned expected = 19u;
    
    const auto edit = dp::edit_distance(s, t);

    EXPECT_EQ(edit, expected);
}

TEST(EditDistance, ManyReplacements)
{
    constexpr unsigned length = 300;
    const std::string s(length, 'A');
    const std::string t(length, 'B');

    const auto edit = dp::edit_distance(s, t);

    EXPECT_EQ(edit, length);
}
