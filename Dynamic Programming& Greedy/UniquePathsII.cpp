#include "stdafx.h"
#include <algorithm>
#include <vector>

using namespace std;

class UniquePathsII {
public:
    static int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size();
		if(m == 0)
			return 0;

		int n = obstacleGrid[0].size();
		if(n == 0)
			return 0;

        vector<vector<int> > pathNum(m, vector<int>(n, 0));

		if(obstacleGrid[0][0] == 1)
			return 0;

		pathNum[0][0] = 1;

		for(int i = 0; i < n; i ++){
			if(obstacleGrid[0][i] != 1)
				pathNum[0][i] = 1;
		}

		for(int i = 1; i < m; i++){
			if(obstacleGrid[i][0] != 1)
				pathNum[i][0] = 1;
			for(int j = 1; j < n; j++){
				if(obstacleGrid[i][j] != 1)
					pathNum[i][j] = pathNum[i-1][j] + pathNum[i][j-1];
			}
		}

		return pathNum[m-1][n-1];
    }
};