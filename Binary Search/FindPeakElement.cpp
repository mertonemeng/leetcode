#include "stdafx.h"
#include <vector>

using namespace std;

class FindPeakElement {
public:
    static int findPeakElement(const vector<int> &num) {
		int n = num.size() - 1;
		int start = 0, middle = n/2, end = n - 1;
		if(num.size() == 1)return 0;
		if(num[n] > num[n-1])return n;
		if(num[0] > num[1])return 0;
		while (1)
		{
			if(num[middle]<num[middle + 1])
			{
				start = middle + 1;
				middle = start + (end - start)/2;
			}
			else if(num[middle]<num[middle - 1])
			{
				end = middle - 1;
				middle = start + (end - start)/2;
			}
			else
			{
				return middle;
			}
		}

		return middle;
    }
};