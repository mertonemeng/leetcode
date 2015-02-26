#include "stdafx.h"
#include <vector>
#include <ctype.h>

using namespace std;

class PalindromePartitioning {
public:
    static vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> curPatition;

		if(s.empty()){
			curPatition.push_back("");
			result.push_back(curPatition);
			return result;
		}

		BackTracking(s, result, curPatition);

		return result;
    }

	static void BackTracking(string s, vector<vector<string>> &result, vector<string> &curPatition){
		
		if(s.empty()){
			result.push_back(curPatition);
			return;
		}

		for(int i = 1; i <= s.size();i++){
			string curStr = s.substr(0,i);
			if(!isPalindrome(curStr))
				continue;
			else{
				curPatition.push_back(curStr);
			}
			BackTracking(s.substr(i), result, curPatition);
			curPatition.pop_back();
		}
	}

	static bool isPalindrome(string s) {

        int i = 0, j = s.size() - 1;
        while(i < j)
        {
            while(i < j && !isalnum(s[i])) i++;
            while(i < j && !isalnum(s[j])) j--;
            if (toupper(s[i])!=toupper(s[j]))
                return false;
            i++;j--;
        }
        return true;
    }
};