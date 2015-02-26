#include "stdafx.h"
#include <vector>

using namespace std;

class LongestCommonPrefix {
public:
    static string longestCommonPrefix(vector<string> &strs) {
        string result = "";
		bool matchFlag = true;
		int j = 0;

		if(strs.empty())
			return result;

		while (1){
			int size = strs[0].size();
			if(j > size - 1){
				return result;
			}
			char temp = strs[0][j];
			for(int i = 1; i < strs.size(); i++){
				if(j > strs[i].size() - 1){
					return result;
				}
				if(temp != strs[i][j]){
					matchFlag = false;
				}
			}
			if(matchFlag){
				result += temp;
			}
			else{
				return result;
			}
			j++;
		}
    }
};