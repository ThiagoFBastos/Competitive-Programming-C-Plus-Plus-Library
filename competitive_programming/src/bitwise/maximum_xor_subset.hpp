#pragma once

#include <vector>
#include <algorithm>

namespace bitset {

using value_type = unsigned long long;

inline value_type maximum_xor_subset(std::vector<value_type> arr) {
    constexpr int max_bits = 64;

    value_type result {};

    for (int i = max_bits - 1; i >= 0; --i) 
    {
        value_type max_element {};

        for (const auto& num : arr) 
        {
            if((num >> i) & 1) 
                max_element = std::max(max_element, num);
        }

        if(max_element == 0) continue;

        if((result ^ max_element) > result)
            result ^= max_element;

        for(auto& num : arr) 
        {
            if((num >> i) & 1)
                num ^= max_element;
        }
    }

    return result;
}

}