#include "stdafx.h"
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {

		if(grid.empty())
			return 0;

		int row = grid.size();
		int col = (grid[0]).size();
		vector<vector<int> > cache(row, vector<int>(col, 0));

		cache[0][0] = grid[0][0];

		for(int i = 1; i  < col; i++){
			cache[0][i] = cache[0][i-1] + grid[0][i];
		}

		for(int i = 1; i  < row; i++){
			cache[i][0] = cache[i - 1][0] + grid[i][0];
			for(int j = 1; j < col; j++){
				cache[i][j] = min(cache[i - 1][j], cache[i][j - 1]) + grid[i][j];
			}
		}

		return cache[row - 1][col - 1];
    }
};