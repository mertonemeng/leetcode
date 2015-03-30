#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class PermutationsII {
public:
    static vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
		vector<int> currentPerm;

		sort(num.begin(), num.end());

		searchHelper(num, result, currentPerm);

		return result;
    }

	static void searchHelper(vector<int> &num, vector<vector<int> > &result, vector<int> &currentPerm){

		if(num.size() == 0){
			result.push_back(currentPerm);
			return;
		}

		vector<int> temp = num;

		for(int i = 0; i < temp.size(); i++){
			if(i != 0 && num[i] == num[i - 1]){
				continue;
			}
			currentPerm.push_back(num[i]);
			num.erase(num.begin() + i);
			searchHelper(num, result, currentPerm);
			num = temp;
			currentPerm.pop_back();
		}

	}
};