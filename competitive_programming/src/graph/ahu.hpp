#pragma once

#include <map>
#include <vector>
#include <optional>
#include <algorithm>
#include <cassert>

#include "graph/tree_center.hpp"

namespace graph {

using adjacency_list = std::vector<std::vector<int>>;

class Ahu
{
public:
    Ahu() = default;

    int dfs(const adjacency_list& g, int u, std::optional<int> p)
    {
        std::vector<int> patterns;

        for(const auto& v : g[u])
        {
            if(!p || *p != v)
                patterns.emplace_back(dfs(g, v, u));
        }

        std::sort(patterns.begin(), patterns.end());

        if(auto it = vec2Id.find(patterns); it != vec2Id.end())
            return it->second;

        return vec2Id[patterns] = vec2Id.size();
    }

    int get_rooted_tree_patter(const adjacency_list& g, int root)
    {
        assert(!g.empty());
        return dfs(g, root, std::nullopt);
    }

    int get_tree_cannonical_pattern(const adjacency_list& g)
    {
        int cannonical {};

        if(g.empty())
            return {};

        for(const auto v : center(g))
            cannonical = std::max(cannonical, dfs(g, v, std::nullopt));

        return cannonical;
    }

public:
    std::map<std::vector<int>, int> vec2Id;
};

}