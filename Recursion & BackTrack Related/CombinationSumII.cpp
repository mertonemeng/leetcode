#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class CombinationSumII {
public:
    static vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
		vector<int> currentComb;
		int currentSum = 0;
		int currentPos = 0;

		if(num.empty())
			return result;

		sort(num.begin(), num.end());

		Backtracking(num, result, currentComb, currentSum, currentPos, target);

		sort(result.begin(), result.end());
		result.erase( unique( result.begin(), result.end() ), result.end() );

		return result;
    }

	static void Backtracking(vector<int> &num, vector<vector<int> > &result, vector<int> &currentComb, int currentSum, int currentPos, int target){

		for(int i = currentPos; i < num.size(); i++){
			currentSum += num[i];
			currentComb.push_back(num[i]);
			if(target == currentSum){
				sort( currentComb.begin(), currentComb.end() );
				result.push_back(currentComb);
				currentComb.pop_back();
				return;
			}
			else if(currentSum < target){
				Backtracking(num, result, currentComb, currentSum, i + 1, target);
			}
			currentComb.pop_back();
			currentSum -= num[i];
		}
	}
};