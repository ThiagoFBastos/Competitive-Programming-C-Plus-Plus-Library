#pragma once

namespace math {

using value_type = long long;

/**
 * @brief Find \sum_{i=0}^{n-1} \left\lfloor \frac{a i + b}{m} \right\rfloor
 */
inline value_type sum_floor(value_type n, value_type m, value_type a, value_type b)
{
    auto linSum = [](auto l, auto r)
    {
        return (r - l + 1) * (l + r) / 2;
    };

    auto sum = [linSum](auto& self, auto n, auto m, auto a, auto b)
    {
        if(!a)
            return b * n;

        long long k = (a * (n - 1) + b) / m;
        
        __int128 s = b * n + static_cast<__int128>(a) * linSum(0, n - 1);

        __int128 t = k * (n - 1)
        - ((a + (-b - 1) % a) % a
        +  static_cast<__int128>(m) * linSum(1, k)
        -  static_cast<__int128>(k) * (b + 1)
        - self(self, k + 1, a, m % a, (a + (-b - 1) % a) % a)) / a;
        
        return static_cast<value_type>(s - m * t);
    };

    auto s = static_cast<__int128>(b) * n + static_cast<__int128>(a) * linSum(0, n - 1) - sum(sum, n, m, a, b);

    return static_cast<value_type>(s / m);
}
}