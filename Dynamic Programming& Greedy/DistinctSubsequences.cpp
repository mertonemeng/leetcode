#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class DistinctSubsequences {
public:
    int numDistinct(string S, string T) {
		int n = S.size();
		int m = T.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

		for(int i = 0; i < n + 1; i++){
			dp[0][i] = 1;
		}

		for (int i = 1; i <= T.size(); i++) {  
			for (int j = 1; j <= S.size(); j++) {  
			  dp[i][j] = dp[i][j - 1];  
			  if (T[i - 1] == S[j - 1]) {  
				dp[i][j] += dp[i - 1][j - 1];  
			  }  
			}  
		}  

		return dp[m][n];
    }
};