#pragma once

#include <set>
#include <functional>

struct line 
{
	long long m, b;
	static long long nu, de;
	bool is_query;
	mutable std::function<const line*()> succ;
	line(long long _m, long long _b, bool iq = false) : m {_m}, b {_b}, is_query {iq} {}
	bool operator<(const line& o) const 
    {
		if(!o.is_query) return m < o.m;
		const line *s = succ();
		if(!s) return false;
		return (b - s->b) * de < (s->m - m) * nu;
	}
};

long long line :: nu = 0;
long long line :: de = 0;

template<bool maxcht>
struct DynamicHull : public std::multiset<line> 
{
	bool bad(iterator y) 
    {
		auto z = next(y);
		if(y == begin()) 
        {
			if(z == end()) return false;
			return y->m == z->m && y->b <= z->b;
		}
		auto x = prev(y);
		if(z == end()) return y->m == z->m && y->b <= x->b;
		return (x->b - y->b) * (z->m - y->m) >= (y->b - z->b) * (y->m - x->m);			
	}

	void insert_line(long long m, long long b) 
    {
		if(!maxcht) m *= -1, b *= -1;
		auto y = insert(line(m, b));
		y->succ = [=, this] {return next(y) == end() ? 0 : &*next(y);};
		if(bad(y)) {erase(y); return;}
		while(next(y) != end() && bad(next(y))) erase(next(y));
		while(y != begin() && bad(prev(y))) erase(prev(y));
	}

	long long query(long long a, long long b) 
    {
		if(b < 0) a *= -1, b *= -1;
		line :: nu = a;
		line :: de = b;
		auto l = lower_bound(line(0, 0, true));
		long long y = l->m * a + l->b;
		if(!maxcht) y *= -1;
		return y;
	}
};