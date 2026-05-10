#pragma once

#include <queue>
#include <vector>
#include <optional>
#include <utility>

namespace graph {

using result_type = std::optional<long long>;
using adjacency_list = std::vector<std::vector<std::pair<int, long long>>>;

inline std::vector<result_type> dijkstra(const adjacency_list& adj, std::size_t start)
{
    using pq_type = std::pair<long long, int>;

    const auto n = adj.size();

    std::vector<result_type> dist(n);
    std::priority_queue<pq_type, std::vector<pq_type>, std::greater<pq_type>> pq;

    pq.emplace(0LL, start);

    while(!pq.empty())
    {
        auto [cost, start] = pq.top();

        pq.pop();

        if(dist[start].has_value())
            continue;

        dist[start] = cost;

        for(const auto& [dest, weight] : adj[start])
        {
            if(dist[dest].has_value())
                continue;

            pq.emplace(cost + weight, dest);
        }
    }

    return dist;
}

}