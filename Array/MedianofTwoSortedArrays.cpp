#include "stdafx.h"
#include <climits>

class MedianofTwoSortedArrays {
public:
    static double findMedianSortedArrays(int A[], int m, int B[], int n) {
        
		int length = m + n;
		
		if(length % 2== 0){
			return (double)(findKth(A, m, B, n, length/2) + findKth(A, m, B, n, length/2 + 1)) / 2 ;
		}
		else{
			return (double)findKth(A, m, B, n, length/2 + 1);
		}

    }

	static int findKth(int A[], int m, int B[], int n, int k){
		int total = k;
		int count = 0;
		int *result = nullptr;

		if(m == 0)
			return *(B + k - 1);
		if(n == 0)
			return *(A + k - 1);

		if(k == 1)
			return *A > *B ? *B : *A;

		int A_key = k/2 - 1 < m? *(A + k/2 - 1) : INT_MAX;
		int B_key = k/2 - 1 < n? *(B + k/2 - 1) : INT_MAX;

		if(A_key < B_key)
			return findKth(A + k/2, m - k/2, B, n, k - k/2);
		else
			return findKth(A, m, B + k/2, n - k/2, k - k/2);

	}
};