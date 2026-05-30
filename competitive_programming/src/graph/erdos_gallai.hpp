#pragma once

#include <vector>
#include <queue>
#include <algorithm>

namespace graph {

inline bool erdos_gallai(std::vector<int> degrees)
{
    const auto n = degrees.size();

    std::sort(degrees.rbegin(), degrees.rend());

    std::vector<long long> prefix_sum(n + 1, 0);
    std::priority_queue<int> pq;
    long long right_sum {}, cnt {};

    for(std::size_t i = 1; i <= n; ++i)
        prefix_sum[i] = prefix_sum[i - 1] + degrees[i - 1];

    bool possible = prefix_sum[n] % 2 == 0;

    for(std::size_t i = n; i > 0; --i)
    {
        if(!possible)
            break;

        while(!pq.empty() && pq.top() >= static_cast<int>(i))
        {
            auto val = pq.top();
            pq.pop();
            right_sum -= val;
            ++cnt;
        }

        possible = possible && prefix_sum[i] <= static_cast<long long>(i) * static_cast<long long>(i - 1) + right_sum + cnt * static_cast<long long>(i);
        
        pq.push(degrees[i - 1]);
        right_sum += degrees[i - 1];
    }

    return possible;
}

}