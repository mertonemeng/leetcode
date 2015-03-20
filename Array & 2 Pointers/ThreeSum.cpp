#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class ThreeSum {
public:
	//Hash Table Ver.
    static vector<vector<int> > threeSum(vector<int> &num) {
        unordered_map<int, vector<vector<int> >> hashTable;
		vector<vector<int> > result;

		if(num.empty())
			return result;

		sort(num.begin(), num.end());

		for(int i = 0; i < num.size();i++){
			vector<int> currentIdx;
				currentIdx.push_back(i);
			if(i != 0 && num[i] == num[i - 1])
				continue;
			for(int j = i+1; j < num.size(); j++){
				currentIdx.push_back(j);
				int twoSum = num[i] + num[j];
				auto it = hashTable.find(twoSum);

				if(it != hashTable.end()){
					(it->second).push_back(currentIdx);
				}else{
					vector<vector<int> > temp;
					temp.push_back(currentIdx);
					hashTable[twoSum] = temp;
				}
				currentIdx.pop_back();
			}
			currentIdx.pop_back();
		}

		for(int i = 0; i < num.size();i++){
			auto it = hashTable.find(-num[i]);
			if(it != hashTable.end()){
				for(int j = 0; j < (it->second).size(); j++){
					if((i != (it->second)[j][0]) && (i != (it ->second)[j][1])){
						vector<int> temp;
						temp.push_back(num[(it->second)[j][0]]);
						temp.push_back(num[(it->second)[j][1]]);
						temp.push_back(num[i]);
						sort(temp.begin(), temp.end());
						result.push_back(temp);
					}
				}
			}
		}

		for(int i = 0; i < result.size(); i++){
			for(int j = i + 1; j < result.size();){
				if(sameVector(result[i], result[j])){
					result.erase(result.begin()+j);
				}
				else{
					j++;
				}
			}
		}

		return result;
    }

	static bool sameVector(vector<int> a, vector<int> b){
		for(int i = 0; i < 3; i++){
			if(a[i] != b[i])
				return false;
		}

		return true;
	}
	//Two Pointer Ver.

};