#include <gtest/gtest.h>

#include "dp/edit_distance.hpp"

TEST(EditDistance, SimpleTest) 
{
    std::string s = "LOVE";
    std::string t = "MOVIE";

    int edit = dp::edit_distance(s, t);

    EXPECT_EQ(edit, 2);
}

TEST(EditDistance, NoOperations) 
{
    std::string s = "A";
    std::string t = "A";

    int edit = dp::edit_distance(s, t);

    EXPECT_EQ(edit, 0);
}

TEST(EditDistance, OneOperation)
{
    std::string s = "A";
    std::string t = "B";

    int edit = dp::edit_distance(s, t);

    EXPECT_EQ(edit, 1);
}

TEST(EditDistance, ManyOperations)
{
    std::string s = "TWXFUABGBNLTBFNSUVQW";
    std::string t = "GPNJILFXJUIZPLTVUIB";

    int edit = dp::edit_distance(s, t);

    EXPECT_EQ(edit, 19);
}

TEST(EditDistance, ManyReplacements)
{
    constexpr int length = 300;
    std::string s(length, 'A');
    std::string t(length, 'B');

    int edit = dp::edit_distance(s, t);

    EXPECT_EQ(edit, length);
}
