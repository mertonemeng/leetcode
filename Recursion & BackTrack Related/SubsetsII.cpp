#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class SubsetsII {
public:
    static vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<int> currentSet;
		vector<vector<int> > result;
		int currentPos = 0;

		if(S.empty())
			return result;

		result.push_back(currentSet);

		sort(S.begin(), S.end());

		backTracking(S, currentSet, result, currentPos);

		return result;
    }

	static void backTracking(vector<int> &S, vector<int> &currentSet, vector<vector<int> > &result, int currentPos){
		int lastElem = 0;
		
		if(currentPos > S.size())
			return;

		for(int i = currentPos; i < S.size(); i++){
			if((i == currentPos) || (lastElem != S[i])){
				currentSet.push_back(S[i]);
				result.push_back(currentSet);
				lastElem = S[i];
				backTracking(S, currentSet, result, i + 1);
				currentSet.pop_back();
			}
		}
	}
};