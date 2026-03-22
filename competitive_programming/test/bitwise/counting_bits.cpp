#include <gtest/gtest.h>

#include "bitwise/counting_bits.hpp"

using namespace bitwise;

TEST(CountingBits, CountingOneBitsTest)
{
    EXPECT_EQ(counting_bits(1LL), 1LL);
    EXPECT_EQ(counting_bits(2LL), 2LL);
    EXPECT_EQ(counting_bits(3LL), 4LL);
    EXPECT_EQ(counting_bits(4LL), 5LL);
    EXPECT_EQ(counting_bits(5LL), 7LL);
    EXPECT_EQ(counting_bits(6LL), 9LL);
    EXPECT_EQ(counting_bits(7LL), 12LL);
    EXPECT_EQ(counting_bits(8LL), 13LL);
    EXPECT_EQ(counting_bits(9LL), 15LL);
    EXPECT_EQ(counting_bits(10LL), 17LL);
    EXPECT_EQ(counting_bits(303021765044187LL), 7250167017244884LL);
    EXPECT_EQ(counting_bits(390977392667778LL), 9400236781929604LL);
    EXPECT_EQ(counting_bits(670904313808571LL), 16399391652009372LL);
    EXPECT_EQ(counting_bits(704275111916256LL), 17252936460583174LL);
    EXPECT_EQ(counting_bits(799807335176164LL), 19646099779305746LL);
    EXPECT_EQ(counting_bits(852012055430877LL), 21005540865890493LL);
    EXPECT_EQ(counting_bits(901305628563213LL), 22232965316761961LL);
    EXPECT_EQ(counting_bits(917427461591619LL), 22650112032503064LL);
    EXPECT_EQ(counting_bits(981787468874797LL), 24322274256024775LL);
    EXPECT_EQ(counting_bits(1000000000000000LL), 24784747400675348LL);
    EXPECT_EQ(counting_bits(989898989898989LL), 24531282955144033LL);
}