#include <gtest/gtest.h>

#include "data_structures/disjoint_set.hpp"

TEST(DisjointSet, DisconnectedGraphTest)
{
    constexpr std::size_t N = 10;

    data_structures::DisjointSet uf(N);

    for(std::size_t u = 1; u < N; ++u)
        for(std::size_t v = 0; v < u; ++v)
            EXPECT_FALSE(uf.is_same(u, v));

    for(std::size_t u = 0; u < N; ++u)
    {
        EXPECT_EQ(uf.findSet(u), u);
        EXPECT_EQ(uf.getSize(u), 1u);
    }
}

TEST(DisjointSet, PathTest)
{
    constexpr std::size_t N = 10;

    data_structures::DisjointSet uf(N);

    for(std::size_t u = 1; u < N; ++u)
        uf.unite(0, u);

    const auto root = uf.findSet(0);

    for(std::size_t u = 0; u < N; ++u)
    {
        EXPECT_EQ(uf.findSet(u), root);
        EXPECT_EQ(uf.getSize(u), N);
    }
}

TEST(DisjointSet, CompleteGraphTest)
{
    constexpr std::size_t N = 10;

    data_structures::DisjointSet uf(N);

    for(std::size_t u = 1; u < N; ++u)
        for(std::size_t v = 0; v < u; ++v)
            uf.unite(u, v);

    for(std::size_t u = 1; u < N; ++u)
        for(std::size_t v = 0; v < u; ++v)
            EXPECT_TRUE(uf.is_same(u, v));

    const auto root = uf.findSet(0);

    for(std::size_t u = 0; u < N; ++u)
    {
        EXPECT_EQ(uf.findSet(u), root);
        EXPECT_EQ(uf.getSize(u), N);
    }
}

TEST(DisjointSet, SplittedPathsTest)
{
    constexpr std::size_t N = 10;

    data_structures::DisjointSet uf(N);

    for(std::size_t u = 2; u < N; ++u)
        uf.unite(u % 2, u);

    const std::size_t root[] = {uf.findSet(0), uf.findSet(1)};

    EXPECT_NE(root[0], root[1]);

    for(std::size_t u = 0; u < N; ++u)
    {
        EXPECT_EQ(uf.findSet(u), root[u % 2]);
        EXPECT_EQ(uf.getSize(u), N / 2);
    }
}

