#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class CombinationSumII {
public:
    static vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
		vector<int> currentComb;

		if(num.empty())
			return result;

		sort(num.begin(), num.end());

		Backtracking(num, result, currentComb, 0, target);

		return result;
    }

	static void Backtracking(vector<int> &num, vector<vector<int> > &result, vector<int> &currentComb, int currentPos, int target){

		if(target == 0){
			result.push_back(currentComb);
			return;
		}

		for(int i = currentPos; i < num.size(); i++){
			if(num[i] > target)
				return;
			if(i != currentPos && num[i] == num[i - 1])
				continue;
			currentComb.push_back(num[i]);
			Backtracking(num, result, currentComb, i + 1, target - num[i]);
			currentComb.pop_back();
		}
	}
};