#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

class MajorityElement  {
public:
    static int majorityElement(vector<int> &num) {
		int least = 0;
        for(int i = 0;i < (num.size()-1);i++)
		{
			least = i;
			for(int j = i + 1; j<num.size(); j++)
			{
				if(num[j] < num[least])least = j;
			}
			swap(num[least], num[i]);
		}

		return num[num.size()/2];
    }

	static void swap(int &x, int &y)
	{
		if(x != y)
		{
			int temp = x;
			x = y;
			y = temp;
		}
	}
};