#pragma once

namespace bitwise {

/**
 * @brief Count the number of one bits in the binary representations of integers between 1 and n
 */
inline long long counting_bits(long long n)
{
    long long ones {}, remainder {1}, pow {1};

    for(int i {}; n > 0; ++i)
    {
        ones += (n & 1) * (remainder + (pow >> 1) * i);
        remainder += (n & 1) * pow;
        pow <<= 1;
        n >>= 1;
    }

    return ones;
}

}