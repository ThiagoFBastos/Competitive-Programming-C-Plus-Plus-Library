#pragma once

#include <cassert>

namespace math {

inline int totient(int n)
{
    int result = 1;

    assert(n > 0);

    if(~n & 1)
    {
        do
        {
            n >>= 1;
            result <<= 1;
        } while (~n & 1);
        
        result >>= 1;
    }

    for(int k = 3; k * k <= n; k += 2)
    {
        if(n % k)
            continue;

        do
        {
            n /= k;
            result *= k;
        } while (n % k == 0);

        result = result / k * (k - 1);
    }

    if(n > 1)
        result *= n - 1;

    return result;
}
}