#pragma once

/**
 * Author: Thiago Felipe Bastos da Silva
 * Created: 2026-01-24
 * Description: Simple implementation of a sparse table data structure that can answer RMQ queries
 * and operations that need of log operations to be concluded
 */

#include <vector>
#include <cassert>
#include <concepts>
#include <iterator>
#include <functional>

template <typename T>
class SparseTable
{
public:
    /**
     * @brief initialize the sparse table data structure
     * @param begin the start iterator of the sequence
     * @param end the end iterator of the sequence
     * @param op the binary function that calculates the answer
     */
    template <typename It, typename F>
	requires std::regular_invocable<F, T, T>
	&& std::same_as<std::invoke_result_t<F, T, T>, T>
	&& std::same_as<typename std::iterator_traits<It>::value_type, T>
    SparseTable(It begin, It end, F&& op)
    {
        std::size_t n = std::distance(begin, end);

        assert(n != 0);

        std::size_t lg = 32 - __builtin_clz(n);

        _st.resize(lg);

        _st[0] = std::vector<T>(begin, end);
        
        for(std::size_t i = 1; i < lg; ++i)
            _st[i].resize(n);

        for(std::size_t i = 1; i < lg; ++i)
            for(std::size_t j = 0; j + (1 << i) <= n; ++j)
                _st[i][j] = op(_st[i - 1][j], _st[i - 1][j + (1 << (i - 1))]);

		_query_constant = [this, op](std::size_t l, std::size_t r)
		{
			assert(l <= r && r < _st[0].size());

			std::size_t lg = 31 - __builtin_clz(r - l + 1);

			return op(_st[lg][l], _st[lg][r + 1 - (1 << lg)]);
		};

		_query_log = [this, op](T initial, std::size_t l, std::size_t r)
		{
			assert(l <= r && r < _st[0].size());

			auto distance = r - l + 1;
			std::size_t lg = 31 - __builtin_clz(distance);

			T answer = initial;

			for(std::size_t i = 0; i <= lg; ++i)
			{
				if(distance & (1 << i))
				{
					answer = op(answer, _st[i][l]);
					l += (1 << i);
				}
			}

			return answer;
		};
    }

    /**
     * @brief answer the value of constant query operation
     * @param l the leftmost index of interval
     * @param r the rightmost index of interval
     */
    T query(std::size_t l, std::size_t r) const
    {
        return _query_constant(l, r);
    }

    /**
     * @brief answer the value of log query operation
     * @param initial the start value of the variable with the answer
     * @param l the leftmost index of interval
     * @param r the rightmost index of interval
     */
    T query(T initial, std::size_t l, std::size_t r) const
    {
        return _query_log(initial, l, r);
    }

private:
    /* the sparse table data */
    std::vector<std::vector<T>> _st;

    /* the constant query function */ 
    std::function<T(std::size_t, std::size_t)> _query_constant;

    /* the log query function */
	std::function<T(T, std::size_t, std::size_t)> _query_log;
};