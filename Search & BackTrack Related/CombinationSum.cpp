#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class CombinationSum {
public:
    static vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
		vector<int> currentComb;
		
		if(candidates.empty())
			return result;

		sort(candidates.begin(), candidates.end());

		Backtracking(candidates, result, currentComb, 0, target);

		return result;
    }

	static void Backtracking(vector<int> &candidates, vector<vector<int> > &result, vector<int> &currentComb, int currentPos, int target){

		if(target == 0){
			result.push_back(currentComb);
			return;
		}

		for(int i = currentPos; i < candidates.size(); i++){
			if(candidates[i] > target) return;
			currentComb.push_back(candidates[i]);
			Backtracking(candidates, result, currentComb, i, (target - candidates[i]));
			currentComb.pop_back();
		}
	}
};