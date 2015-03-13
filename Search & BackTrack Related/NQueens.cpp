#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;

class NQueens {
public:
    static vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > result;
		vector<string> curSolution(n, string(n, '.'));

		if(n == 0){
			return result;
		}

		vector<bool> rowFlag(n, false);
		vector<bool> colFlag(n, false);
		vector<bool> diagnalFlag1(2*n - 1, false);
		vector<bool> diagnalFlag2(2*n - 1, false);

		backTrack2(result, colFlag, diagnalFlag1, diagnalFlag2, curSolution, 0, n);

		return result;
    }

	static void backTrack(vector<vector<string> > &result, vector<bool> &rowFlag, vector<bool> &colFlag, 
		vector<bool> &diagnalFlag1, vector<bool> &diagnalFlag2, vector<string> &curSolution, int curRow, int queenNum){

		if(queenNum == 0){
			result.push_back(curSolution);
			return;
		}

		int n = curSolution.size();

		for(int i = curRow;i < n; i++){
			if(rowFlag[i]){
				continue;
			}
			for(int j = 0; j < n; j++){
				if(colFlag[j] || diagnalFlag1[i-j+n-1] || diagnalFlag2[i+j]){
					continue;
				}
				curSolution[i][j] = 'Q';
				rowFlag[i] = true;
				colFlag[j] = true;
				diagnalFlag1[i-j+n-1] = true;
				diagnalFlag2[i+j] = true;
				backTrack(result, rowFlag, colFlag, diagnalFlag1, diagnalFlag2, curSolution, i + 1, queenNum - 1);
				curSolution[i][j] = '.';
				rowFlag[i] = false;
				colFlag[j] = false;
				diagnalFlag1[i-j+n-1] = false;
				diagnalFlag2[i+j] = false;
			}
		}
	}

	static void backTrack2(vector<vector<string> > &result, vector<bool> &colFlag, 
		vector<bool> &diagnalFlag1, vector<bool> &diagnalFlag2, vector<string> &curSolution, int curRow, int queenNum){

		if(queenNum == 0){
			result.push_back(curSolution);
			return;
		}

		int n = curSolution.size();

		for(int j = 0; j < n; j++){
			if(colFlag[j] || diagnalFlag1[curRow-j+n-1] || diagnalFlag2[curRow+j]){
				continue;
			}
			curSolution[curRow][j] = 'Q';
			colFlag[j] = true;
			diagnalFlag1[curRow-j+n-1] = true;
			diagnalFlag2[curRow+j] = true;
			backTrack2(result, colFlag, diagnalFlag1, diagnalFlag2, curSolution, curRow + 1, queenNum - 1);
			curSolution[curRow][j] = '.';
			colFlag[j] = false;
			diagnalFlag1[curRow-j+n-1] = false;
			diagnalFlag2[curRow+j] = false;
		}
	}
};