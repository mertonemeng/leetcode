#include "stdafx.h"
#include <vector>

using namespace std;

class SetMatrixZeroes {
public:
    void setZeroes(vector<vector<int> > &matrix) {

		int m = matrix.size();
		if(m == 0)
			return;

		int n = matrix[0].size();
		if(n == 0)
			return;

        vector<bool> rowFlag(m, false);
		vector<bool> colFlag(n, false);

		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][j] == 0){
					rowFlag[i] = true;
					colFlag[j] = true;
				}
			}
		}

		for(int i = 0; i < m; i++){
			if(rowFlag[i]){
				for(int j = 0; j < n; j++){
					matrix[i][j] = 0;
				}
			}
		}

		for(int i = 0; i < n; i++){
			if(colFlag[i]){
				for(int j = 0; j < m; j++){
					matrix[j][i] = 0;
				}
			}
		}
    }
};