#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class TwoSum {
public:
    static vector<int> twoSum(vector<int> &numbers, int target) {
        
		unordered_map<int, vector<int>> hashTable;
		vector<int> result;

		if(numbers.empty())
			return result;

		for(int i = 0; i < numbers.size(); i++){
			vector<int> idx;
			idx.push_back(i + 1);
			hashTable[target - numbers[i]] = idx;
		}

		for(int i = 0; i < numbers.size(); i++){
			auto it = hashTable.find(numbers[i]);
			if(it != hashTable.end()){
				if(hashTable[numbers[i]][0] != i+1){
					hashTable[numbers[i]].push_back(i + 1);
					result = hashTable[numbers[i]];
					break;
				}
			}
		}

		sort(result.begin(), result.end());
		return result;
    }
};