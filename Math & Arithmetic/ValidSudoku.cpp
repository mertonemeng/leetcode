#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
		char sudokuTable[] = {'1','2','3','4','5','6','7','8','9'};
		int rowCount = 0,colCount = 0;
        for(int i = 0; i < 9; i++)
		{
			for(int k = 0;k < 9;k++)
			{
				rowCount = 0;
				colCount = 0;
				for(int j = 0; j < 9; j++)
				{
					if(board[i][j] == sudokuTable[k])
					{
						rowCount++;
					}
					if(board[j][i] == sudokuTable[k])
					{
						colCount++;
					}
					if(rowCount > 1 || colCount >1)return false;
				}
			}
		}

		rowCount = 0;
		colCount = 0;

		for(int m = 0;m < 9;m+=3)
			for(int n = 0;n < 9;n+=3)
				for(int k = 0;k < 9;k++)
				{
					rowCount = 0;
					for(int i = 0; i < 3; i++)
					{
						for(int j = 0; j < 3; j++)
						{
							if(board[i+m][j+n] == sudokuTable[k])
							{
								rowCount++;
							}
							if(rowCount > 1)return false;
						}
					}
				}

		return true;
    }
};