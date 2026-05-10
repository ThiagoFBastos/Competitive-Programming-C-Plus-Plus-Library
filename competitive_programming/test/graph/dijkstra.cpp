#include <gtest/gtest.h>

#include "graph/dijkstra.hpp"

#include <random>
#include <chrono>

using namespace graph;

void add_edge(adjacency_list& adj, std::size_t u, std::size_t v, long long weight)
{
    adj[u].emplace_back(v, weight);
    adj[v].emplace_back(u, weight);
}

TEST(Dijkstra, MultipleSimplePathTreeTest)
{
    constexpr std::size_t N = 8;

    adjacency_list adj(N);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long long> uid(static_cast<int>(1e5), static_cast<int>(1e9));

    for(std::size_t i = 1; i < N; ++i)
    {
        add_edge(adj, i - 1, i, i);
        add_edge(adj, i - 1, i, uid(gen));
    }

    auto dist = dijkstra(adj, 0);
    long long total_dist {};

    EXPECT_EQ(dist.size(), N);

    for(std::size_t i = 0; i < N; ++i)
    {
        total_dist += i;

        EXPECT_TRUE(static_cast<bool>(dist[i]));
        EXPECT_EQ(*dist[i], total_dist);
    }
}

TEST(Dijkstra, CompleteGraphTest)
{
    constexpr std::size_t N = 8;
    constexpr std::size_t source = 3;

    adjacency_list adj(N);
     std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long long> uid(static_cast<int>(1e5), static_cast<int>(1e9));

    for(std::size_t i = 0; i < N; ++i)
    {
        for(std::size_t j = i + 1; j < N; ++j)
        {
            if(i == source || j == source)
                add_edge(adj, i, j, 1);
            else
                add_edge(adj, i, j, uid(gen));
        }
    }

    auto dist = dijkstra(adj, source);

    EXPECT_EQ(dist.size(), N);

    for(std::size_t i = 0; i < N; ++i)
    {
        EXPECT_TRUE(static_cast<bool>(dist[i]));

        if(i == source)
            EXPECT_EQ(*dist[i], 0);
        else
            EXPECT_EQ(*dist[i], 1);
    }
}