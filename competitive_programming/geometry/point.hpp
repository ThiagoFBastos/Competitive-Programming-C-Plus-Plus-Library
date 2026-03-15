#pragma once

#include <cmath>

constexpr double EPS = 1e-9;

struct point {
	double x, y;

	point() : x(), y() {}
	point(double _x, double _y) : x {_x}, y {_y} {}

	double norm() const {
		return std::hypot(x, y);
	}

	point normalized() const {
		return point(x, y) * (1.0 / norm());
	}

	double angle() const {
		return std::atan2(y, x);
	}

	double polarAngle() const {
		double a = std::atan2(y, x);
		return a < 0 ? a + 2 * std::acos(-1) : a;
	}

	bool operator<(const point& other) const {
		if(std::fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y;		
	}

	bool operator>(const point& other) const {
		if(std::fabs(x - other.x) > EPS)
			return x > other.x;
		return y > other.y;		
	}

	bool operator<=(const point& other) const {
		if(std::fabs(x - other.x) > EPS)
			return x < other.x;
		return y <= other.y;		
	}
	
	bool operator>=(const point& other) const {
		if(std::fabs(x - other.x) > EPS)
			return x < other.x;
		return y >= other.y;		
	}
	
	bool operator==(const point& other) const {
		return std::fabs(x - other.x) < EPS && std::fabs(y - other.y) < EPS;
	}

	bool operator!=(const point& other) const {
		return !(*this == other);
	}

	point operator+(const point& other) const {
		return {x + other.x, y + other.y};
	}

	point operator-(const point& other) const {
		return {x - other.x, y - other.y};
	}

	point& operator+=(const point& other) {
		x += other.x;
		y += other.y;
		return *this;
	}
	
	point& operator-=(const point& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	point& operator*=(double k) {
		x *= k;
		y *= k;		
		return *this;
	}

	point operator*(double k) const {
		return {x * k, y * k};
	}
};

namespace point_utils
{
inline double dist(const point& p1, const point& p2) {
	return std::hypot(p1.x - p2.x, p1.y - p2.y);
}

inline double inner(const point& p1, const point& p2) {
	return p1.x * p2.x + p1.y * p2.y;
}

inline double cross(const point& p1, const point& p2) {
	return p1.x * p2.y - p1.y * p2.x;
}

inline bool ccw(const point& p, const point& q, const point& r) {
	return cross(q - p, r - p) > EPS;
}

inline bool cw(const point& p, const point& q, const point& r) {
	return cross(q - p, r - p) < -EPS;
}

inline bool collinear(const point& p, const point& q, const point& r) {
	return std::fabs(cross(p - q, r - p)) < EPS;
}

inline point rotate(const point& p, double rad) {
	return {p.x * std::cos(rad) - p.y * std::sin(rad), p.x * std::sin(rad) + p.y * std::cos(rad)};
}

inline double angle(const point& a, const point& o, const point& b) {
	return std::acos(inner(a - o, b - o) / dist(o, a) * dist(o, b));
}

inline point proj(const point& u, const point& v) {
	return v * (inner(u, v) / inner(v, v));
}

inline bool between(const point& p, const point& q, const point& r) {
	return collinear(p, q, r) && inner(p - q, r - q) <= 0;
}

inline point lineIntersectSeg(const point& p, const point& q, const point& A, const point& B) {
	double c = cross(A - B, p - q);
	double a = cross(A, B);
	double b = cross(p, q);
	return (p - q) * (a / c) - (A - B) * (b / c);
}

inline bool parallel(const point& a, const point& b) {
	return std::fabs(cross(a, b)) < EPS;
}	

inline bool segIntersects(const point& a, const point& b, const point& p, const point& q) {
	if(parallel(a - b, p - q))
		return between(a, p, b) || between(a, q, b) || between(p, a, q) || between(p, b, q);

	auto i = lineIntersectSeg(a, b, p, q);

	return between(a, i, b) && between(p, i, q);
}

inline point closestToLineSegment(const point& p, const point& a, const point& b) {
	double u = inner(p - a, b - a) / inner(b - a, b - a);
	if(u < 0) return a;
	if(u > 1) return b;
	return a + (b - a) * u;
}

}
