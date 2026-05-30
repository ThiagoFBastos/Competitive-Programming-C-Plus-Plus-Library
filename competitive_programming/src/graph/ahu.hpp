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

    /**
     * @brief Find the pattern of a given rooted tree
     * @param g The adjacency list
     * @param root The root of the tree
     */
    int get_rooted_tree_pattern(const adjacency_list& g, int root)
    {
        assert(!g.empty());
        return dfs(g, root, std::nullopt);
    }

    /**
     * @brief Find a unique pattern of a given tree
     * @param g The adjacency list of the tree
     */

    int get_tree_cannonical_pattern(const adjacency_list& g)
    {
        int cannonical {};

        if(g.empty())
            return {};

        for(const auto v : center(g))
            cannonical = std::max(cannonical, get_rooted_tree_pattern(g, v));

        return cannonical;
    }

private:

    /**
     * @brief Do a DFS from the root to the others nodes
     * @param g The adjacency list of the tree
     * @param u The node of current subtree
     * @param p The parent of the node u
     */
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

    /* The map between the array of patterns and the pattern of a subtree */
    std::map<std::vector<int>, int> vec2Id;
};

}