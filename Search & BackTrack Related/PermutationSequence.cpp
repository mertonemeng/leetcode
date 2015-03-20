#include "stdafx.h"
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {

		string result = "";

		if(n == 0){
			return result;
		}

		for(int i = 1; i <= n; i++){
			result += to_string(i);
		}

		for(int i; i < k; i++){
			next_permutation(result.begin(), result.end());
		}
		
		return result;
    }
};