#pragma once

#include <vector>
#include <queue>
#include <algorithm>
#include <ranges>

/**
 * @brief Find the center and diameter of a tree
 */

namespace graph
{

/**
 * Compute the time until a node becomes a leaf
 * @param adj the adjacency list of the tree
 */
inline std::vector<int> bfs(const std::vector<std::vector<int>>& adj)
{
    const auto n = adj.size();
    std::vector<int> deg(n), dist(n);
    std::queue<int> q;

    for(std::size_t i = 0; i < n; ++i)
    {
        deg[i] = adj[i].size();

        if(deg[i] <= 1)
        {
            q.push(i);
            dist[i] = 0;
        }
    }

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : adj[u])
        {
            if(--deg[v] == 1)
            {
                q.push(v);
                dist[v] = 1 + dist[u];
            }
        }
    }

    return dist;
}

/**
 * Find the center of a tree
 * @param adj the adjacency list of the tree
 */
inline std::vector<int> center(const std::vector<std::vector<int>>& adj)
{
    const auto dist = bfs(adj);

    int max_dist = *std::max_element(dist.begin(), dist.end());

    std::vector<int> c;

    auto filtered = std::views::iota(std::size_t {}, adj.size() + 1)
                    | std::views::filter([&](auto v) { return dist[v] == max_dist; })
                    | std::views::transform([](auto v) { return static_cast<int>(v); });

    std::ranges::copy(filtered, std::back_inserter(c));

    return c;
}

/**
 * Find the diameter of a tree
 * @param adj the adjacency list of the tree
 */
inline int diameter(const std::vector<std::vector<int>>& adj)
{
    const auto dist = bfs(adj);

    int max_dist = *std::max_element(dist.begin(), dist.end());

    return 2 * max_dist + std::count(dist.begin(), dist.end(), max_dist) - 1;
}

}
