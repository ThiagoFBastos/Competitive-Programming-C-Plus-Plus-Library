#pragma once

#include <vector>
#include <utility>
#include <optional>
#include <algorithm>

namespace graph {

class Centroid
{
public:

    using adjacency_list = std::vector<std::vector<int>>;

    Centroid(const adjacency_list& adj)
        : _adj(adj)
        , size(adj.size(), 0)
    {

    }

    int findCentroid()
    {
        return dfs(0, std::nullopt).value();
    }

private:

    std::optional<int> dfs(int u, std::optional<int> p)
    {
        size[u] = 1;

        for(const auto& v : _adj[u])
        {
            if(p && *p == v)
                continue;

            std::ignore = dfs(v, u);

            size[u] += size[v];
        }

        if(p) return std::nullopt;

        auto answer = std::make_pair(0, 0);
        auto parent = std::make_optional<int>();

        const int n = _adj.size();

        do
        {
            answer = std::make_pair(0, 0);

            for(const auto& v : _adj[u])
            {
                if(parent && *parent == v) continue;
                answer = std::max(answer, std::make_pair(size[v], v));
            }

            parent = u;
            u = answer.second;
        } while(std::max(answer.first, n - size[*parent]) > n / 2);
        
        return parent.value();
    }

    const adjacency_list& _adj;
    std::vector<int> size;
};
}