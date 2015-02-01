#include "stdafx.h"
#include <vector>

using namespace std;

class SearchA2DMatrix {
public:
    static bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rowStart = 0, rowEnd = matrix.size() - 1, rowMid = 0;;
		int colStart = 0, colEnd = matrix[0].size() - 1, colMid = 0;
		int rowIdx = 0;

		if(matrix.size() == 0)return false;

		while(rowStart < rowEnd)
		{
			rowMid = rowStart + (rowEnd - rowStart)/2;
			if(matrix[rowMid][0] == target)return true;
			else if(matrix[rowMid][0] > target)
			{
				rowEnd = rowMid - 1;
			}
			else if (matrix[rowMid][0] < target)
			{
				rowStart = rowMid + 1;
			}
		}
		
		if(matrix[rowStart][0] > target)
		{
			if(rowStart>0)rowIdx = rowStart - 1;
			else rowIdx = 0;
		}
		else if(matrix[rowStart][0] == target) return true;
		else rowIdx = rowStart;

		while(colStart < colEnd)
		{
			colMid = colStart + (colEnd - colStart)/2;
			if(matrix[rowIdx][colMid] == target)return true;
			else if(matrix[rowIdx][colMid] > target)
			{
				colEnd = colMid - 1;
			}
			else if (matrix[rowIdx][colMid] < target)
			{
				colStart = colMid + 1;
			}
		}
		if(matrix[rowIdx][colStart] == target) return true;
		else return false;
    }
};