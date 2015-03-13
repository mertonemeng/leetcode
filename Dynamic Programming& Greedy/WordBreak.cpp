#include "stdafx.h"
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class WordBreak {
public:
    static bool wordBreak(string s, unordered_set<string> &dict) {
        
		int n = s.size();

		if(n == 0)
			return false;

		vector<bool> breakCache(n + 1, false);

		breakCache[0] = true;

		for(int i = 1; i <= n; i++){
			for(int j = 0; j < i; j++){
				auto it = dict.find(s.substr(j, i - j));
				breakCache[i] = (breakCache[j] && (it != dict.end()));
				if(breakCache[i])
					break;
			}
		}

		return breakCache[n];
    }
};