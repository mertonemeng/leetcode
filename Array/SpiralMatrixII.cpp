#include "stdafx.h"
#include <vector>

using namespace std;

class SpiralMatrixII {
public:
    static vector<vector<int> > generateMatrix(int n) {
        int top = 0, bottom = n, left = 0, right = n;
		int count = 0;
		int directFlag = 0;
		vector<int> row;
		vector<vector<int> > result;
		
		if(n == 0)return result;

		for(int i = 0; i < n; i++){
			row.push_back(0);
		}
		for(int i = 0; i < n; i++){
			result.push_back(row);
		}
		int i = 1;
		while(i <= n*n){
			switch (directFlag)
			{
			case 0:
				if(count < right){
					result[top][count] = i;
					count++;
					i++;
				}
				else{
					top++;
					count = top;
					directFlag = 1;
				}
				break;
			case 1:
				if(count < bottom){
					result[count][right - 1] = i;
					count++;
					i++;
				}
				else{
					right--;
					count = right - 1;
					directFlag = 2;
				}
				break;
			case 2:
				if(count >= left){
					result[bottom - 1][count] = i;
					count--;
					i++;
				}
				else{
					bottom--;
					count = bottom - 1;
					directFlag = 3;
				}
				break;
			case 3:
				if(count >= top){
					result[count][left] = i;
					count--;
					i++;
				}
				else{
					left++;
					count = left;
					directFlag = 0;
				}
				break;
			default:
				break;
			}
		}

		return result;
    }
};