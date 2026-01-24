#pragma once

/*
 * Author: Thiago Felipe Bastos da Silva
 * Created: 2026-01-24
 * Description: Simple implementation of Union Find data structure.
 */

#include <vector>
#include <numeric>
#include <utility>

class DisjointSet
{
public:

    /**
     * initialize the DisjointSet data structure
     * @param n the number of vertices
     */ 
    DisjointSet(std::size_t n):
        parent(n),
        rank(n, 0),
        size(n, 1)
    {
        std::iota(parent.begin(), parent.end(), 0);
    }

    /**
     * Find the root of the disjoint set that v belongs
     * @param v a vertex number in [0, n)
     */
    std::size_t find_set(std::size_t v)
    {
        return v != parent[v] ? parent[v] = find_set(parent[v]) : v;
    }

    /**
     * Join the disjoint sets that u and v belong to, if u and v are in the same set nothing happens
     * @param u a vertex number in [0, n)
     * @param v a vertex number in [0, n)
     */
    void unite(std::size_t u, std::size_t v)
    {
        u = find_set(u);
        v = find_set(v);

        if(u == v)  return;
        else if(rank[u] > rank[v]) std::swap(u, v);

        parent[u] = v;
        size[v] += size[u];
        rank[v] += rank[u] == rank[v];
    }

    /**
     * Return true if u and v belong to the same connected component, and false otherwise
     * @param u a vertex number in [0, n)
     * @param v a vertex number in [0, n)
     */ 
    inline bool same(std::size_t u, std::size_t v)
    {
        return find_set(u) == find_set(v);
    }

    /**
     * Return the number of vertices of a disjoint set
     * @param v a vertex number in [0, n)
     */
    inline unsigned getSize(std::size_t v)
    {
        return size[find_set(v)];
    }

private:

    /* the parent of each vertex */
    std::vector<std::size_t> parent;

    /* the rank of each vertex */
    std::vector<unsigned> rank;

    /* the size of each disjoint set */
    std::vector<unsigned> size;
};