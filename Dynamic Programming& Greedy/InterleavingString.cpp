#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class InterleavingString {
public:
    static bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
		int m = s2.size();

		if(m + n != s3.size()){
			return false;
		}

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

		dp[0][0] = true;

		for(int i = 1; i < n + 1; i++){
			dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
		}

		for(int i = 1; i < m + 1; i++){
			dp[0][i] = dp[0][i - 1] && (s2[i - 1] == s3[i - 1]);
		}

		for(int i = 1; i < n + 1; i++){
			for(int j = 1; j < m + 1; j++){
				dp[i][j] = (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
			}
		}

		return dp[n][m];
    }
};