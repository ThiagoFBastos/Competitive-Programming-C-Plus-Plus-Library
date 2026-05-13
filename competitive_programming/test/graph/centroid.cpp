#include <gtest/gtest.h>

#include "graph/centroid.hpp"

using adjacenty_list = graph::Centroid::adjacency_list;

adjacenty_list build_tree(const std::vector<std::pair<int, int>>& edges)
{
    const auto n = edges.size() + 1;

    adjacenty_list adj(n);

    for(const auto& [u, v] : edges)
    {
        adj[u - 1].emplace_back(v - 1);
        adj[v - 1].emplace_back(u - 1);
    }

    return adj;
}

TEST(Centroid, CentroidTestSample1)
{
    std::vector<std::pair<int, int>> edges {
        {4, 1},
        {6, 5},
        {7, 2},
        {6, 3},
        {1, 7},
        {2, 10},
        {10, 9},
        {3, 8},
        {8, 9}
    };

    auto adj = build_tree(edges);

    graph::Centroid centroindFinder(adj);

    int centroid = centroindFinder.findCentroid();

    EXPECT_TRUE(centroid == 8 || centroid == 9);
}

TEST(Centroid, CentroidTestSample2)
{
    std::vector<std::pair<int, int>> edges = {
        {8, 5},
        {7, 4},
        {2, 6},
        {3, 9},
        {6, 8},
        {4, 1},
        {3, 10},
        {5, 10},
        {1, 2}
    };

    auto adj = build_tree(edges);

    graph::Centroid centroindFinder(adj);

    int centroid = centroindFinder.findCentroid();

    EXPECT_TRUE(centroid == 5 || centroid == 7);
}

TEST(Centroid, CentroidTestSample3)
{
    std::vector<std::pair<int, int>> edges = {
        {6, 4},
        {1, 3},
        {10, 8},
        {9, 3},
        {2, 7},
        {5, 4},
        {2, 4},
        {8, 5},
        {9, 5}
    };

    auto adj = build_tree(edges);

    graph::Centroid centroindFinder(adj);

    int centroid = centroindFinder.findCentroid();

    EXPECT_TRUE(centroid == 4 || centroid == 8);
}

TEST(Centroid, CentroidTestSample4)
{
    std::vector<std::pair<int, int>> edges = {
        {3, 6},
        {9, 1},
        {4, 5},
        {2, 9},
        {7, 6},
        {8, 4},
        {3, 5},
        {10, 1},
        {4, 1}
    };

    auto adj = build_tree(edges);

    graph::Centroid centroindFinder(adj);

    int centroid = centroindFinder.findCentroid();

    EXPECT_TRUE(centroid == 0 || centroid == 3);
}

TEST(Centroid, CentroidTestSample5)
{
    std::vector<std::pair<int, int>> edges = {
        {3, 1},
        {9, 8},
        {6, 5},
        {2, 9},
        {4, 7},
        {3, 4},
        {3, 9},
        {5, 3},
        {6, 10}
    };

    auto adj = build_tree(edges);

    graph::Centroid centroindFinder(adj);

    int centroid = centroindFinder.findCentroid();

    EXPECT_TRUE(centroid == 2);
}

TEST(Centroid, CentroidTestSample6)
{
    std::vector<std::pair<int, int>> edges = {{1, 2}};

    auto adj = build_tree(edges);

    graph::Centroid centroindFinder(adj);

    int centroid = centroindFinder.findCentroid();

    EXPECT_TRUE(centroid == 0 || centroid == 1);
}

TEST(Centroid, CentroidTestSample7)
{
    std::vector<std::pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };

    auto adj = build_tree(edges);

    graph::Centroid centroindFinder(adj);

    int centroid = centroindFinder.findCentroid();

    EXPECT_TRUE(centroid == 2);
}

TEST(Centroid, CentroidTestSample8)
{
    std::vector<std::pair<int, int>> edges = {
        {1, 5},
        {5, 4},
        {4, 3},
        {3, 2}
    };

    auto adj = build_tree(edges);

    graph::Centroid centroindFinder(adj);

    int centroid = centroindFinder.findCentroid();

    EXPECT_TRUE(centroid == 3);
}

TEST(Centroid, CentroidTestSample9)
{
    std::vector<std::pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {1, 4},
        {4, 5},
        {5, 6},
        {2, 7},
        {2, 8},
        {2, 9}
    };

    auto adj = build_tree(edges);

    graph::Centroid centroindFinder(adj);

    int centroid = centroindFinder.findCentroid();

    EXPECT_TRUE(centroid == 1);
}