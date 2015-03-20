#include "stdafx.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Anagrams  {
public:
    static vector<string> anagrams(vector<string> &strs) {
		int n = strs.size();

		vector<string>  result;
		unordered_map<string, vector<int>> hashTable;

		if(n == 0){
			return result;
		}

		for(int i = 0; i < n; i++){
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			hashTable[temp].push_back(i);
		}

		auto it = hashTable.begin();

		while(it != hashTable.end()){
			if((it ->second).size() > 1){
				for(int j = 0; j < (it ->second).size(); j++){
					result.push_back(strs[(it ->second)[j]]);
				}
			}
			it++;
		}

		return result;
    }
};