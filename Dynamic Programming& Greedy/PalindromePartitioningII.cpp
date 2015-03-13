#include "stdafx.h"
#include <string>
#include <vector>
#include <climits>
using namespace std;

class PalindromePartitioningII {
public:
    static int minCut(string s) {
		int n = s.size();
		if(n == 0)
			return 0;

        vector<int> minCutCache(n+1,0);

		minCutCache[0] = -1;

		for(int i = 1; i < minCutCache.size();i++){
			minCutCache[i] = i - 1;
		}

		vector<vector<bool>> isPalindorme = getIsPalindrome(s);

		for(int i = 1; i < minCutCache.size(); i++){
			int minCutVal = INT_MAX;
			for(int j = 1; j <= i; j++){
				if(isPalindorme[i - j][i - 1]){
					minCutVal = minCutVal > (minCutCache[i - j] + 1)?
						(minCutCache[i - j] + 1):minCutVal;
				}
			}
			minCutCache[i] = minCutVal > minCutCache[i]?
						minCutCache[i]:minCutVal;
		}

		return minCutCache[s.size()];
    }

	static vector<vector<bool>> getIsPalindrome(string s) {
        vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length(), false));

        for (int i = 0; i < s.length(); i++) {
            isPalindrome[i][i] = true;
        }
        for (int i = 0; i < s.length() - 1; i++) {
            isPalindrome[i][i + 1] = (s[i] == s[i+1]);
        }

        for (int length = 2; length < s.length(); length++) {
            for (int start = 0; start + length < s.length(); start++) {
                isPalindrome[start][start + length]
                    = isPalindrome[start + 1][start + length - 1] && s[start] == s[start + length];
            }
        }

        return isPalindrome;
    }

	static bool isValidPalindorme(string s){
		int start = 0;
		int end = s.size() - 1;

		while(start <= end){
			if(s[start] != s[end])
				return false;
			start++;
			end--;
		}

		return true;
	}
};