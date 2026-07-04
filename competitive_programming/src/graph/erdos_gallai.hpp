#pragma once

#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>

namespace graph {

inline bool erdos_gallai(std::vector<int> degrees)
{
    const auto n = degrees.size();

    std::sort(degrees.rbegin(), degrees.rend());

    long long left_sum = std::accumulate(degrees.begin(), degrees.end(), 0ll);
    std::stack<int> st;
    long long right_sum {}, cnt {};

    bool is_possible = left_sum % 2 == 0;

    for(std::size_t i = n; i > 0 && is_possible; --i)
    {
        while(!st.empty() && st.top() >= static_cast<int>(i))
        {
            auto val = st.top();
            st.pop();
            right_sum -= val;
            ++cnt;
        }

        is_possible = is_possible && left_sum <= static_cast<long long>(i) * static_cast<long long>(i - 1) + right_sum + cnt * static_cast<long long>(i);
        
        st.push(degrees[i - 1]);
        left_sum -= degrees[i - 1];
        right_sum += degrees[i - 1];
    }

    return is_possible;
}

}