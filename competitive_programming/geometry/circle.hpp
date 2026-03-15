#pragma once

#include "point.hpp"

#include <cmath>
#include <vector>
#include <utility>
#include <cassert>
#include <algorithm>
#include <chrono>
#include <random>

struct circle 
{
	point c;
	double r;

	circle(): c(), r() {}

	circle(point _c, double _r) : c {_c}, r {_r} {}

	double area() const 
	{
		return std::acos(-1) * r * r;
	}

	double chord(double rad) const 
	{
		return 2 * r * std::sin(rad / 2);
	}

	double sector(double rad) const 
	{
		return 0.5 * rad * area() / std::acos(-1);
	}

	bool intersects(const circle& other) const 
	{
		return point_utils::dist(c, other.c) < r + other.r;
	}

	bool contains(const point& p) const 
	{
		return point_utils::dist(c, p) <= r + EPS;
	}

	std::pair<point, point> getTangentPoint(const point& p) const 
	{
		double d1 = point_utils::dist(p, c);
		double theta = std::asin(r / d1);
		auto p1 = point_utils::rotate(c - p, -theta);
		auto p2 = point_utils::rotate(c - p, theta);
		p1 = p1 * (std::sqrt(d1 * d1 - r * r) / d1) + p;
		p2 = p2 * (std::sqrt(d1 * d1 - r * r) / d1) + p;	
		return {p1, p2};
	}

	std::vector<std::pair<point, point>> getTangentSegs(const circle& other) const 
	{
		std::vector<std::pair<point, point>> ans;
		
		double d = point_utils::dist(other.c, c);

		double dr = std::abs(r - other.r), sr = r + other.r;

		if(dr >= d) return ans;

		double u = std::acos(dr / d);

		point dc1 = (other.c - c).normalized() * r;
		point dc2 = (other.c - c).normalized() * other.r;

		ans.push_back({c + point_utils::rotate(dc1, u), other.c + point_utils::rotate(dc2, u)});
		ans.push_back({c + point_utils::rotate(dc1, -u), other.c + point_utils::rotate(dc2, -u)});

		if(sr >= d) return ans;

		double v = acos(sr / d);

		dc2 = (c - other.c).normalized() * other.r;

		ans.push_back({c + point_utils::rotate(dc1, v), other.c + point_utils::rotate(dc2, v)});
		ans.push_back({c + point_utils::rotate(dc1, -v), other.c + point_utils::rotate(dc2, -v)});

		return ans;
	}

	std::pair<point, point> getIntersectionPoints(const circle& other) const
	{
		assert(intersects(other));
		
		double d = point_utils::dist(c, other.c);

		double u = std::acos((r * r + d * d - other.r * other.r) / (2 * r * d));

		auto dc = (other.c - c).normalized() * r;

		return {c + point_utils::rotate(dc, u), c + point_utils::rotate(dc, -u)};	
	}
};

namespace circle_utils {
	
circle circumcircle(const point& a, const point& b, const point& c) 
{
	point u = {(b - a).y, -(b - a).x};
	point v = {(c - a).y, -(c - a).x};
	auto n = (c - b) * 0.5;
	circle ans;
	double t = point_utils::cross(u, n) / point_utils::cross(v, u);
	ans.c = (a + c) * 0.5 + v * t;
	ans.r = point_utils::dist(ans.c, a);
	return ans; 
}

int insideCircle(const point& p, const circle& c) 
{
	if(std::fabs(point_utils::dist(p, c.c) - c.r) < EPS) return 1;
	else if(point_utils::dist(p, c.c) < c.r) return 0;
	return 2; // 0 = inside /1 = border /2 = outside
}	

circle incircle(const point& p1, const point& p2, const point& p3) 
{
	double m1 = point_utils::dist(p2, p3);
	double m2 = point_utils::dist(p1, p3);
	double m3 = point_utils::dist(p1, p2);
	auto c = (p1 * m1 + p2 * m2 + p3 * m3) * (1.0 / (m1 + m2 + m3));
	double s = 0.5 * (m1 + m2 + m3);
	double r = sqrt(s * (s - m1) * (s - m2) * (s - m3)) / s;
	return {c, r};
}

circle minimumCircle(std::vector<point>& p) 
{
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

	std::shuffle(p.begin(), p.end(), rng);
	int n = p.size();
	circle C(p[0], 0.0);
	for(int i = 0; i < n; ++i) {
		if(C.contains(p[i])) continue;
		C = circle(p[i], 0.0);
		for(int j = 0; j < i; ++j) {
			if(C.contains(p[j])) continue;
			C = circle((p[j] + p[i]) * 0.5, 0.5 * point_utils::dist(p[j], p[i]));
			for(int k = 0; k < j; ++k) {
				if(C.contains(p[k])) continue;
				C = circumcircle(p[j], p[i], p[k]);
			}
		}
	}
	return C;
}

}
