#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Subsets {
public:
    static vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
		vector<int> currentSet;
		int currentPos = 0; 

		sort(S.begin(), S.end());

		result.push_back(currentSet);

		backTracking(S, result, currentPos, currentSet);

		return result;
    }

	static void backTracking(vector<int> &S, vector<vector<int> > &result, int currentPos, vector<int> &currentSet){

		if(currentPos > S.size())
			return;

		for(int i = currentPos; i < S.size(); i++){
			currentSet.push_back(S[i]);
			result.push_back(currentSet);
			backTracking(S, result, i + 1, currentSet);
			currentSet.pop_back();
		}
	}
};