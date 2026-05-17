#pragma once

#include <string>
#include <vector>
#include <algorithm>

namespace strings {

inline int manacher(const std::string& s)
{
    const auto n = static_cast<int>(s.size());

    std::vector<int> d1(n, 1), d2(n, 0);

    int l = 0, r = -1, len = 0;

    for(int i = 0; i < n; ++i)
    {
        if(i <= r)
        {
            d1[i] = std::min(d1[l + r - i], r + 1 - i);
            d2[i] = std::min(d2[l + r + 1 - i], r + 1 - i);
        }

        while(i + d1[i] < n && i >= d1[i] && s[i - d1[i]] == s[i + d1[i]])  ++d1[i];
        while(i + d2[i] < n && i > d2[i] && s[i - d2[i] - 1] == s[i + d2[i]]) ++d2[i];

        if(r < i + d2[i] - 1) l = i - d2[i], r = i + d2[i] - 1;
        if(r < i + d1[i] - 1) l = i + 1 - d1[i], r = i + d1[i] - 1;

        len = std::max(len, r + 1 - l);
    }

    return len;
}
}