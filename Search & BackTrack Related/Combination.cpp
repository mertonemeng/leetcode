#include "stdafx.h"
#include <vector>

using namespace std;

class Combination {
public:
    static vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
		vector<int> currentComb;
		int currentPos = 1;

		if(n <= 0 || k <=0)
			return result;

		backTracking(result, currentComb, currentPos, n, k);

		return result;
    }

	static void backTracking(vector<vector<int> > &result, vector<int> &currentComb, int currentPos, int n, int k){

		if(k == 0){
			result.push_back(currentComb);
			return;
		}

		for(int i = currentPos; i <= n; i++){
			currentComb.push_back(i);
			backTracking(result, currentComb, i + 1, n, k - 1);
			currentComb.pop_back();
		}
	}
};