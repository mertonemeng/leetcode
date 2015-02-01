#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;

class PascalTriangle {
public:
    static vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;

		for(int i = 0; i < numRows;i++)
		{
			vector<int> temp;
			for(int j = 0; j <= i;j++)
			{
				int element = 0;
				if((j == 0)||(j == i))element = 1;
				else element = result[i-1][j-1] + result[i-1][j];
				temp.push_back(element);
			}
			result.push_back(temp);
		}
		return result;
    }
};