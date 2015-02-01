#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;

class PascalTriangle2 {
public:
	   static vector<int> getRow(int rowIndex) {
        vector<int> result;

		for(int i = 0; i < rowIndex + 1;i++)
		{
			vector<int> temp;
			temp = result;
			result.clear();
			for(int j = 0; j <= i;j++)
			{
				int element = 0;
				if((j == 0)||(j == i))element = 1;
				else element = temp[j-1] + temp[j];
				result.push_back(element);
			}
		}
		return result;
    }
};