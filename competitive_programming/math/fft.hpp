#pragma once

#include <complex>
#include <cmath>
#include <vector>
#include <utility>

namespace math {

using cd = std::complex<double>;

inline void fft(std::vector<cd>& a, bool invert) { 	
    const double PI = std::acos(-1);

    int n = a.size();

    for(int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;	
        for(; j & bit; bit >>= 1) j -= bit;
        j += bit;
        if(i < j) std::swap(a[i], a[j]);
    }

    for(int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(std::cos(ang), std::sin(ang));
        int mid = len >> 1;
        for(int i = 0; i < n; i += len) {
            cd w(1);
            for(int j = 0; j < mid; ++j) {
                cd u = a[i + j], v = a[i + j + mid] * w;
                a[i + j] = u + v;
                a[i + j + mid] = u - v;
                w *= wlen;
            }
        }
    }

    if(invert) for(int i = 0; i < n; ++i) a[i] /= n;
}

inline void multiply(std::vector<int>& result, const std::vector<int>& a, const std::vector<int>& b) {

    std::vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    
    auto lg = [](int x) {
        return x ? 31 - __builtin_clz(x) : 0;
    };

    int n = 2 << lg(a.size() + b.size());

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for(int i = 0; i < n; ++i) fa[i] *= fb[i];

    fft(fa, true);

    result.resize(n);
    for(int i = 0; i < n; ++i) result[i] = (int)std::round(fa[i].real());
}

}
