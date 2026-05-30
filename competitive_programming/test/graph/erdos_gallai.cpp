#include <gtest/gtest.h>


#include "graph/erdos_gallai.hpp"

using namespace graph;

// ======================================================
// Casos básicos
// ======================================================

TEST(ErdosGallaiTest, EmptyGraph)
{
    EXPECT_TRUE(erdos_gallai({}));
}

TEST(ErdosGallaiTest, SingleVertexDegreeZero)
{
    EXPECT_TRUE(erdos_gallai({0}));
}

TEST(ErdosGallaiTest, SingleVertexInvalidDegree)
{
    EXPECT_FALSE(erdos_gallai({1}));
}

TEST(ErdosGallaiTest, TwoVerticesConnected)
{
    EXPECT_TRUE(erdos_gallai({1, 1}));
}

TEST(ErdosGallaiTest, TwoVerticesInvalid)
{
    EXPECT_FALSE(erdos_gallai({1, 0}));
}

// ======================================================
// Soma ímpar
// ======================================================

TEST(ErdosGallaiTest, OddSumMustFail)
{
    EXPECT_FALSE(erdos_gallai({3, 3, 1}));
}

TEST(ErdosGallaiTest, AnotherOddSumCase)
{
    EXPECT_FALSE(erdos_gallai({2, 2, 1, 1, 1}));
}

// ======================================================
// Grafos válidos clássicos
// ======================================================

TEST(ErdosGallaiTest, CompleteGraphK5)
{
    EXPECT_TRUE(erdos_gallai({4, 4, 4, 4, 4}));
}

TEST(ErdosGallaiTest, PathGraph)
{
    // Caminho com 5 vértices
    EXPECT_TRUE(erdos_gallai({2, 2, 2, 1, 1}));
}

TEST(ErdosGallaiTest, CycleGraph)
{
    EXPECT_TRUE(erdos_gallai({2, 2, 2, 2}));
}

TEST(ErdosGallaiTest, StarGraph)
{
    EXPECT_TRUE(erdos_gallai({4, 1, 1, 1, 1}));
}

TEST(ErdosGallaiTest, RegularGraph)
{
    EXPECT_TRUE(erdos_gallai({3, 3, 3, 3}));
}

// ======================================================
// Sequências inválidas clássicas
// ======================================================

TEST(ErdosGallaiTest, DegreeTooLarge)
{
    EXPECT_FALSE(erdos_gallai({5, 1, 1, 1, 1}));
}

TEST(ErdosGallaiTest, ViolatesErdosGallaiInequality)
{
    EXPECT_FALSE(erdos_gallai({4, 4, 1, 1, 1, 1}));
}

TEST(ErdosGallaiTest, AnotherInvalidSequence)
{
    EXPECT_FALSE(erdos_gallai({3, 3, 3, 1}));
}

// ======================================================
// Casos com zeros
// ======================================================

TEST(ErdosGallaiTest, AllZeros)
{
    EXPECT_TRUE(erdos_gallai({0, 0, 0, 0}));
}

TEST(ErdosGallaiTest, MixedWithZerosValid)
{
    EXPECT_TRUE(erdos_gallai({2, 2, 1, 1, 0}));
}

TEST(ErdosGallaiTest, MixedWithZerosInvalid)
{
    EXPECT_FALSE(erdos_gallai({3, 1, 1, 0}));
}

// ======================================================
// Ordem de entrada
// ======================================================

TEST(ErdosGallaiTest, UnsortedValidSequence)
{
    EXPECT_TRUE(erdos_gallai({1, 4, 1, 1, 1}));
}

TEST(ErdosGallaiTest, UnsortedInvalidSequence)
{
    EXPECT_FALSE(erdos_gallai({1, 1, 4, 4, 1, 1}));
}

// ======================================================
// Casos de borda maiores
// ======================================================

TEST(ErdosGallaiTest, LargeCompleteGraph)
{
    constexpr int n = 1000;

    std::vector<int> degrees(n, n - 1);

    EXPECT_TRUE(erdos_gallai(degrees));
}

TEST(ErdosGallaiTest, LargeStarGraph)
{
    constexpr int n = 1000;

    std::vector<int> degrees(n, 1);
    degrees[0] = n - 1;

    EXPECT_TRUE(erdos_gallai(degrees));
}

TEST(ErdosGallaiTest, LargeInvalidGraph)
{
    constexpr int n = 1000;

    std::vector<int> degrees(n, n - 1);
    degrees.back() = 0;

    EXPECT_FALSE(erdos_gallai(degrees));
}

// ======================================================
// Casos mínimos que exercitam desigualdades
// ======================================================

TEST(ErdosGallaiTest, TightEqualityCase)
{
    EXPECT_TRUE(erdos_gallai({3, 3, 2, 2, 2}));
}

TEST(ErdosGallaiTest, NearBoundaryInvalidCase)
{
    EXPECT_FALSE(erdos_gallai({4, 4, 2, 2, 1}));
}

// ======================================================
// Casos degenerados
// ======================================================

TEST(ErdosGallaiTest, ManyZerosOnePositive)
{
    EXPECT_FALSE(erdos_gallai({1, 0, 0, 0, 0}));
}

TEST(ErdosGallaiTest, MaximumValidForSmallN)
{
    EXPECT_TRUE(erdos_gallai({2, 2, 2}));
}

TEST(ErdosGallaiTest, ImpossibleSmallCase)
{
    EXPECT_FALSE(erdos_gallai({2, 2, 1}));
}