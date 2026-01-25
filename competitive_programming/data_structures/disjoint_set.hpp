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
        _parent(n),
        _rank(n, 0),
        _size(n, 1)
    {
        std::iota(_parent.begin(), _parent.end(), 0);
    }

    /**
     * Find the root of the disjoint set that v belongs
     * @param v a vertex number in [0, n)
     */
    std::size_t findSet(std::size_t v)
    {
        return v != _parent[v] ? _parent[v] = findSet(_parent[v]) : v;
    }

    /**
     * Join the disjoint sets that u and v belong to, if u and v are in the same set nothing happens
     * @param u a vertex number in [0, n)
     * @param v a vertex number in [0, n)
     */
    void unite(std::size_t u, std::size_t v)
    {
        u = findSet(u);
        v = findSet(v);

        if(u == v)  return;
        else if(_rank[u] > _rank[v]) std::swap(u, v);

        _parent[u] = v;
        _size[v] += _size[u];
        _rank[v] += _rank[u] == _rank[v];
    }

    /**
     * Return true if u and v belong to the same connected component, and false otherwise
     * @param u a vertex number in [0, n)
     * @param v a vertex number in [0, n)
     */ 
    inline bool is_same(std::size_t u, std::size_t v)
    {
        return findSet(u) == findSet(v);
    }

    /**
     * Return the number of vertices of a disjoint set
     * @param v a vertex number in [0, n)
     */
    inline unsigned getSize(std::size_t v)
    {
        return _size[findSet(v)];
    }

private:

    /* the parent of each vertex */
    std::vector<std::size_t> _parent;

    /* the rank of each vertex */
    std::vector<unsigned> _rank;

    /* the size of each disjoint set */
    std::vector<unsigned> _size;
};