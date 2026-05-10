#include <gtest/gtest.h>

#include "graph/ahu.hpp"

#include <unordered_set>

using namespace graph;

void add_edge(adjacency_list& g, int u, int v)
{
    g[u].emplace_back(v);
    g[v].emplace_back(u);
}

adjacency_list build_tree(const std::vector<int>& parents)
{
    const auto n = parents.size() + 1;
    adjacency_list g(n);

    for(std::size_t i = 0; i < parents.size(); ++i)
    {
        int u = i + 1;
        int v = parents[i] - 1;

        add_edge(g, u, v);
    }

    return g;
}

TEST(Ahu, EmptyTreesTest)
{
    adjacency_list adj1, adj2;

    Ahu ahu;

    auto pattern_adj_1 = ahu.get_tree_cannonical_pattern(adj1);
    auto pattern_adj_2 = ahu.get_tree_cannonical_pattern(adj2);

    EXPECT_EQ(pattern_adj_1, 0);
    EXPECT_EQ(pattern_adj_1, pattern_adj_2);
}

TEST(Ahu, StarTreeTest)
{
    constexpr std::size_t N = 8;

    adjacency_list adj1(N), adj2(N);
    Ahu ahu;

    for(std::size_t i = 0; i < N; ++i)
    {
        if(i != 0)
            add_edge(adj1, 0, i);

        if(i != 1)
            add_edge(adj2, 1, i);
    }

    auto pattern_adj_1 = ahu.get_tree_cannonical_pattern(adj1);
    auto pattern_adj_2 = ahu.get_tree_cannonical_pattern(adj2);

    EXPECT_EQ(pattern_adj_1, pattern_adj_2);
}

TEST(Ahu, DifferentTreesTest)
{
    constexpr std::size_t N = 8;

    adjacency_list adj1(N), adj2(N);
    Ahu ahu;

    for(std::size_t i = 1; i < N; ++i)
    {
        add_edge(adj1, 0, i);
        add_edge(adj2, i - 1, i);
    }

    auto pattern_adj_1 = ahu.get_tree_cannonical_pattern(adj1);
    auto pattern_adj_2 = ahu.get_tree_cannonical_pattern(adj2);

    EXPECT_NE(pattern_adj_1, pattern_adj_2);
}

TEST(Ahu, CountUniqueTreesPatterns)
{
    std::vector<std::vector<int>> data = {
        {1, 1, 1, 1, 3},
        {1, 2, 1, 2, 5},
        {1, 2, 1, 2, 4},
        {1, 2, 3, 1, 1},
        {1, 2, 2, 1, 4},
        {1, 2, 1, 3, 5},
        {1, 2, 1, 3, 5},
        {1, 1, 2, 4, 2},
        {1, 1, 1, 2, 4},
        {1, 2, 1, 4, 1},
        {1, 2, 2, 3, 4},
        {1, 2, 1, 3, 4},
        {1, 1, 1, 3, 4},
        {1, 2, 3, 1, 2},
        {1, 2, 3, 1, 2},
        {1, 1, 3, 2, 5},
        {1, 1, 2, 1, 3},
        {1, 2, 1, 3, 1},
        {1, 1, 3, 3, 5},
        {1, 1, 3, 3, 3},
        {1, 2, 1, 2, 3},
        {1, 2, 2, 4, 3},
        {1, 1, 2, 1, 3},
        {1, 2, 2, 3, 1},
        {1, 1, 3, 3, 1},
        {1, 2, 2, 2, 1},
        {1, 2, 3, 4, 4},
        {1, 1, 2, 3, 1},
        {1, 2, 3, 3, 3},
        {1, 2, 1, 2, 3},
        {1, 1, 3, 2, 3},
        {1, 2, 2, 4, 1},
        {1, 1, 1, 1, 5},
        {1, 2, 3, 3, 4},
        {1, 2, 3, 2, 2},
        {1, 1, 2, 2, 4},
        {1, 2, 3, 4, 2},
        {1, 2, 2, 2, 1},
        {1, 1, 2, 2, 5},
        {1, 1, 2, 3, 5}
    };

    constexpr std::size_t expected_trees = 5;

    Ahu ahu;
    std::unordered_set<int> set;

    for(const auto& parents : data)
    {
        auto g = build_tree(parents);
        auto pattern = ahu.get_tree_cannonical_pattern(g);
        set.emplace(pattern);
    }

    EXPECT_EQ(set.size(), expected_trees);
}