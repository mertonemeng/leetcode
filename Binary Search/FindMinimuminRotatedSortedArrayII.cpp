#include "stdafx.h"
#include "BinaryTree.cpp"
#include <stack>
#include <vector>
#include <climits>
class FindMinimuminRotatedSortedArrayII {
	int findMin(vector<int> &num) {
		int minVal = INT_MAX;
        for(int i = 0; i < num.size(); i++){
			if(num[i]>minVal)
				minVal = num[i];
		}

		return minVal;
    }
};