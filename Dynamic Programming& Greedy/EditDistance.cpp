#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class EditDistance {
public:
    static int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();

		if(n == 0){
			return m;
		} else if(m == 0){
			return n;
		}

		vector<vector<int>> editDistCache(m+1, vector<int>(n+1, INT_MAX));

		for(int i=0; i< m+1; i++){
            editDistCache[0][i] = i; 
        }
        for(int i=0; i<n+1; i++){
            editDistCache[i][0] = i;
        }

		for(int i = 1; i < m+1; i++){
			for(int j = 1; j < n+1; j++){
				if(i == 0){
				} else{
					if(word1[i - 1] == word2[j - 1]){
						int temp = min(editDistCache[i - 1][j - 1], editDistCache[i - 1][j] + 1);
						editDistCache[i][j] = min(editDistCache[i][j - 1]+1, temp);
					} else{
						int temp = min(editDistCache[i - 1][j - 1], editDistCache[i - 1][j] + 1);
						editDistCache[i][j] = min(editDistCache[i][j - 1]+1, temp) + 1;
					}
				}
			}
		}

		return editDistCache[m][n];
    }
};