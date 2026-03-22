#pragma once

#include <iostream>

namespace math {

template<int m>
class mint
{
public:

    using value_type = int;

    static constexpr value_type mod = m;

    static_assert(m > 1, "The modulo must be greater than one");

    mint(): val() {}

    mint(long long v)
    {
        if(v >= 2 * m)
            val = v % m;
        else if(v < -m)
            val = (v % m + m) % m;
        else if(v >= m)
            val = v - m;
        else if(v < 0)
            val = v + m;
        else
            val = v;
    }

    constexpr value_type value() const noexcept
    {
        return val;
    }

    constexpr mint pow(long long n) const noexcept
    {
        mint base = *this, answer(1);


        for(; n > 0; n >>= 1)
        {
            if(n & 1)
                answer *= base;

            base *= base;
        }

        return answer;
    }

    constexpr mint inv() const noexcept
    {
        return pow(m - 2);
    }

    constexpr mint operator+(const mint& rhs) const noexcept
    {
        return {1LL * val + rhs.val};
    }

    constexpr mint operator-(const mint& rhs) const noexcept
    {
        return {1LL * val - rhs.val};
    }

    constexpr mint operator*(const mint& rhs) const noexcept
    {
        return {1LL * val * rhs.val};
    }

    constexpr mint operator/(const mint& rhs) const noexcept
    {
        return *this * rhs.inv();
    }

    constexpr mint& operator+=(const mint& rhs) noexcept
    {
        *this = *this + rhs;
        return *this;
    }

    constexpr mint& operator-=(const mint& rhs) noexcept
    {
        *this = *this - rhs;
        return *this;
    }

    constexpr mint& operator*=(const mint& rhs) noexcept
    {
        *this = *this * rhs;
        return *this;
    }

    constexpr mint& operator/=(const mint& rhs) noexcept
    {
        *this = *this / rhs;
        return *this;
    }

    constexpr explicit operator bool() const noexcept
    {
        return val != 0;
    }

    constexpr mint operator-() const noexcept
    {
        return *this * -1LL;
    }

    constexpr bool operator==(const mint& rhs) const noexcept
    {
        return val == rhs.val;
    }

    constexpr bool operator!=(const mint& rhs) const noexcept
    {
        return !(val == rhs.val);
    }

    template<int m2>
    friend std::istream& operator>>(std::istream&, mint<m2>&);

    template<int m2>
    friend std::ostream& operator<<(std::ostream&, const mint<m2>&);

private:

    value_type val;
};

template<int m>
inline std::istream& operator>>(std::istream& is, math::mint<m>& number)
{
    long long val;
    is >> val;
    number = math::mint<m>{val};
    return is;
}

template<int m>
inline std::ostream& operator<<(std::ostream& os, const math::mint<m>& number)
{
    os << number.val;
    return os;
}

}
