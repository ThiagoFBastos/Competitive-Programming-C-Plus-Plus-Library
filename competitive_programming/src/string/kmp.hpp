#pragma once

#include <vector>
#include <string>

namespace strings {

inline std::vector<int> kmp(const std::string& s) 
{
	int n = s.size();

	if(n == 0)
		return {};
		
	std::vector<int> p(n);
	p[0] = 0;
	for(int i = 1; i < n; ++i) {
		int j = p[i - 1];
		while(j && s[i] != s[j]) j = p[j - 1];
		p[i] = j;
		if(s[i] == s[j]) ++p[i];
	}
	return p;
}

}

