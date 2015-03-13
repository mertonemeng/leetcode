#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class FourSum {
public:
    static vector<vector<int> > fourSum(vector<int> &num, int target) {
        
		unordered_map<int, vector<pair<int, int>>> hashTable;
		vector<vector<int>> result;

		if(num.empty()){
			return result;
		}

		sort(num.begin(), num.end());
		int start = 0;
		int n = num.size();

		for(int i = 0; i < n; i++){
			if(i != 0 && num[i-1] == num[i]){
				continue;
			}
			for(int j = i + 1; j < n; j++){
				if(j != i + 1 && num[j-1] == num[j]){
					continue;
				}
				hashTable[num[i] + num[j]].push_back(make_pair(i,j));
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				int twoSum = num[i] + num[j];
				auto it = hashTable.find(target - twoSum);

				if(it == hashTable.end()){
					continue;
				}
				for(int k = 0; k < (it->second).size() ;k++){
					if((it->second)[k].second >= i){
						continue;
					}
					vector<int> temp;
					temp.push_back(num[(it->second)[k].first]);
					temp.push_back(num[(it->second)[k].second]);
					temp.push_back(num[i]);
					temp.push_back(num[j]);
					result.push_back(temp);
				}
			}
		}

		return result;
    }
};