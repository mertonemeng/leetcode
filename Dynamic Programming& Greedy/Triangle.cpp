#include "stdafx.h"
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Triangle {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		if(triangle.empty())
			return 0;

		int row = triangle.size();
		int maxCol = (triangle[row-1]).size();
		vector<int> rowCache;
		vector<vector<int>> matrixCache;

		for(int i = 0; i < maxCol; i++){
			rowCache.push_back(INT_MAX);
		}

		matrixCache.push_back(rowCache);
		matrixCache.push_back(rowCache);

		for(int i = 0; i < maxCol; i++){
			matrixCache[(row - 1)%2][i] = triangle[row - 1][i];
		}

		for(int i = row - 2; i >= 0; i--){
			for(int j = 0; j < (triangle[i]).size(); j++){
				matrixCache[i%2][j] = min(matrixCache[(i + 1)%2][j], matrixCache[(i + 1)%2][j + 1]) + triangle[i][j];
			}
		}

		return matrixCache[0][0];
    }
};