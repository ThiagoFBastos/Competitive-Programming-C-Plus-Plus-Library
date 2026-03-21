#pragma once

namespace math {

template<typename T>
inline T euclides(T a, T b, T& x, T& y) 
{
	if(b == 0) 
    {
		x = 1, y = 0;
		return a;
	}
	T z, w, g;
	g = euclides(b, a % b, z, w);
	y = z - a / b * w;
	x = w;
	return g;
}

}
