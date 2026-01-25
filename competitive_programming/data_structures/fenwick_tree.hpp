#pragma once

/**
 * Author: Thiago Felipe Bastos da Silva
 * Created: 2026-01-25
 * Description: Simple implementation of a fenwick tree data structure agnostic to operations
 */

#include <concepts>
#include <vector>
#include <cassert>
#include <utility>
#include <type_traits>

template <typename T, typename Op>
requires std::regular_invocable<Op, T, T> && std::same_as<std::invoke_result_t<Op, T, T>, T>
class FenwickTree
{
public:
    /**
     * @brief Initialize the fenwick tree data structure
     * @param n the number of elements
     * @param op the binary operator that calculates the result
     * @param initial the default value that will be used when there is not value
     */
    FenwickTree(std::size_t n, Op&& op, T initial):
        _ft(n + 1, initial),
        _op(op),
        _initial(initial)
    {

    }

    /**
     * @brief Update the fenwick tree data structure
     * @param k the index of a element in the fenwick data structure
     * @param value the value that will be applied to the element
     */
    void update(std::size_t k, T value)
    {
        assert(k >= 1 && k < _ft.size());

        for(int i = k; i < (int)_ft.size(); i += i & -i)
            _ft[i] = _op(_ft[i], value);
    }

    /**
     * @brief Find the result of an operation of first k elements
     * @param k the number of the first elements for which we want to find the result
     */
    T query(std::size_t k) const
    {
        T answer = _initial;

        assert(k < _ft.size());

        for(int i = k; i > 0; i -= i & -i)
            answer = _op(answer, _ft[i]);

        return answer;
    }
private:
    /* The fenwick tree data structure */
    std::vector<T> _ft;

    /* The binary operator that calculates the answer */
    Op _op;

    /* The default value that is used when there is not a value to assign */
    T _initial;
};

/**
  * @brief Factory of the FenwickTree
  * @param n the number of elements
  * @param op the binary operator that calculates the result
  * @param initial the default value that will be used when there is not value
  * @return The FenwickTree data structure
 */
template<typename T, typename Op>
auto make_fenwick_tree(std::size_t n, Op&& op, T initial)
{
    return FenwickTree<T, std::decay_t<Op>>(n, std::forward<Op>(op), initial);
}