#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class LongestConsecutiveSequence {
public:
    static int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> hashtable;
		int result = 0;

		int n = num.size();

		if(n == 0){
			return 0;
		}

		for(int i = 0; i < n;i++ ){
			hashtable[num[i]] = 1;
		}

		auto it = hashtable.begin();

		while(!hashtable.empty()){
			int target = it->first;
			int temp = target + 1;
			int subLen = 0;
			while(hashtable.find(temp) != hashtable.end()){
				hashtable.erase(temp);
				subLen++;
				temp++;
			}

			temp = target - 1;

			while(hashtable.find(temp) != hashtable.end()){
				hashtable.erase(temp);
				subLen++;
				temp--;
			}

			result = max(result, subLen+1);
			it++;
			hashtable.erase(target);
		}

		return result;
    }
};