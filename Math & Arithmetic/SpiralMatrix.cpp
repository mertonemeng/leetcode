#include "stdafx.h"
#include <vector>

using namespace std;

class SpiralMatrix {
public:
    static vector<int> spiralOrder(vector<vector<int> > &matrix) {
		
		vector<int> result;

		if (matrix.size()== 0)return result;

		int rowNum = matrix.size();
		int colNum = matrix[0].size();
		int rowCount = 0, colCount = 0;
		int top = 0, botom = rowNum - 1, left = 0, right = colNum - 1;
		int directionFlag = 0;
		long totalCount = rowNum*colNum;

		while (totalCount > 0)
		{
			result.push_back(matrix[rowCount][colCount]);
			totalCount--;
			if(directionFlag == 0)
			{
				if(colCount == right)
				{
					top++;
					directionFlag = 1;
					rowCount++;
					continue;
				}
				colCount++;
			}
			else if(directionFlag == 1)
			{
				if(rowCount == botom)
				{
					right--;
					directionFlag = 2;
					colCount--;
					continue;
				}
				rowCount++;
			}
			else if(directionFlag == 2)
			{
				if(colCount == left)
				{
					botom--;
					directionFlag = 3;
					rowCount--;
					continue;
				}
				colCount--;
			}
			else
			{
				if(rowCount == top)
				{
					left++;
					directionFlag = 0;
					colCount++;
					continue;
				}
				rowCount--;
			}
		}

		return result;
    }
};