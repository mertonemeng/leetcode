#include "stdafx.h"

class SearchInsertPosition {
public:
    static int searchInsert(int A[], int n, int target) {
        
		int start = 0, end = n - 1;
		int mid = 0;

		//if(target == A[0])return 0;
		//else if(target < A[0])return 0;
		//if(target == A[n - 1])return n - 1;
		//else if(target > A[n - 1])return n;

		while(start < end)
		{
			mid = start + (end - start)/2;
			if(target == A[mid])
			{
				return mid;
			}
			else if (target > A[mid])
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		if(target > A[start])
		{
			return start + 1;
		}
		else
		{
			return start;
		}
    }
};
