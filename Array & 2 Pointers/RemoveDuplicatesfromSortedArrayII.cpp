#include "stdafx.h"

using namespace std;

class RemoveDuplicatesfromSortedArrayII {
public:
    static int removeDuplicates(int A[], int n) {

		if (n == 0)return 0;
		if (n == 1)return 1;
		if(A == nullptr)return 0;

		int duplicateNum = A[0];
		int repeatCount = 0;
		int deleteCount = 0;
		int i = 1, j = 1;
        while(i < n - deleteCount)
		{
			A[i] = A[j];
			if(A[i] == duplicateNum)
			{
				repeatCount++;
				if(repeatCount > 1)
				{
					deleteCount++;
					j++;
					continue;
				}
			}
			if(A[i] != duplicateNum)
			{
				duplicateNum = A[i];
				repeatCount = 0;
			}
			j++;
			i++;
		}

		return n-deleteCount;
    }
};