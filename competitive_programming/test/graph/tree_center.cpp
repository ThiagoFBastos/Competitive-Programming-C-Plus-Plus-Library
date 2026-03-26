#include <gtest/gtest.h>

#include "graph/tree_center.hpp"

#include <algorithm>

class GraphFixture : public ::testing::Test {
protected:
    std::vector<std::vector<int>> adj;

    void SetUp() override 
    {
       
    }

    void TearDown() override 
    {
        adj.clear();
    }

    void initialize(int n)
    {
        adj.resize(n);
    }

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

TEST_F(GraphFixture, StarTreeTest)
{
    const std::vector<int> expectedCenter {0};
    const int expectedDiameter {2};

    initialize(5);

    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(0, 3);
    add_edge(0, 4);

    const auto center = graph::center(adj);
    const auto diameter = graph::diameter(adj);

    EXPECT_EQ(center, expectedCenter);
    EXPECT_EQ(diameter, expectedDiameter);
}

TEST_F(GraphFixture, DoubleStarTreeTest)
{
    const std::vector<int> expectedCenter {0, 1};
    const int expectedDiameter {3};

    initialize(8);

    add_edge(0, 2);
    add_edge(0, 3);
    add_edge(0, 4);
    add_edge(0, 1);
    add_edge(1, 5);
    add_edge(1, 6);
    add_edge(1, 7);

    auto center = graph::center(adj);
    const auto diameter = graph::diameter(adj);

    std::sort(center.begin(), center.end());

    EXPECT_EQ(center, expectedCenter);
    EXPECT_EQ(diameter, expectedDiameter);
}

TEST_F(GraphFixture, EvenTreePathTest)
{   
    const std::vector<int> expectedCenter {3};
    const int expectedDiameter {6};

    initialize(7);

    add_edge(0, 1);
    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(3, 4);
    add_edge(4, 5);
    add_edge(5, 6);

    const auto center = graph::center(adj);
    const auto diameter = graph::diameter(adj);

    EXPECT_EQ(center, expectedCenter);
    EXPECT_EQ(diameter, expectedDiameter);
}

TEST_F(GraphFixture, OddTreePathTest)
{   
    const std::vector<int> expectedCenter {2, 3};
    const int expectedDiameter {5};

    initialize(6);

    add_edge(0, 1);
    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(3, 4);
    add_edge(4, 5);

    auto center = graph::center(adj);
    const auto diameter = graph::diameter(adj);

    std::sort(center.begin(), center.end());

    EXPECT_EQ(center, expectedCenter);
    EXPECT_EQ(diameter, expectedDiameter);
}