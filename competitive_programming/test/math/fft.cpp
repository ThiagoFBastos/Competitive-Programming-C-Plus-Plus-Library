#include <gtest/gtest.h>

#include "math/fft.hpp"

TEST(FFT, CompileTest)
{
    std::vector<int> result;
    std::vector<int> a{0, 1, 0, 0};
    std::vector<int> b{1, 1, 1, 1};

    math::multiply(result, a, b);

    EXPECT_TRUE(true);
}