#include "stdafx.h"
#include <vector>

using namespace std;

class RotateImage {
public:
    static void rotate(vector<vector<int> > &matrix) {
        vector<vector<int>> newMatrix;

		if(matrix.size() == 0)return;

		for(int j = 0; j < matrix[0].size();j++)
		{
			vector<int> newRow;
			for(int i = matrix.size() - 1; i >= 0; i--)
			{
				newRow.push_back(matrix[i][j]);
			}
			newMatrix.push_back(newRow);
		}

		matrix.clear();

		for(int i = 0; i < newMatrix.size(); i++)
		{
			matrix.push_back(newMatrix[i]);
		}
    }
};