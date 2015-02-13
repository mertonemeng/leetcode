#include "stdafx.h"
#include "BinaryTree.cpp"
#include <stack>
#include <vector>

class FindMinimuminRotatedSortedArray {
public:
    static int findMin(vector<int> &num) {

		if(num.empty())
			return 0;
		if(num.size() == 1)
			return num[0];

		int start = 0, end = num.size() - 1;
		int mid = 0;

		while(start + 1 < end){
			mid = start + (end - start)/2;

			if(num[mid] < num[mid + 1] && num[mid] < num[mid - 1]){
				return num[mid];
			}
			if(num[mid] > num[start]){
				start = mid;
			}
			if(num[mid] < num[start]){
				end = mid;
			}
		}

		if(num[0] < num[start] && num[0] < num[end])
			return num[0];
		return num[start] > num[end]?num[end]:num[start];
    }
};