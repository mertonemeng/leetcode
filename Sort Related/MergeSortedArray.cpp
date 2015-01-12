#include "stdafx.h"
#include <vector>
#include <math.h>
using namespace std;

class MergeSortedArray {
public:
    static void merge(int A[], int m, int B[], int n) {
        vector<int> temp;
		int countA = 0, countB = 0;
		int offsetA = 0, offsetB =0;
		for(int i = 0; i < m; i++)
		{
			temp.push_back(A[i]);
		}

		if((A[0] <= A[m-1]) && (B[0] <= B[n-1]))
		{
			offsetA = 0;
			offsetB = 0;
		}
		else if((A[0] <= A[m-1]) && (B[0] >= B[n-1]))
		{
			offsetA = 0;
			offsetB = n - 1;
		}
		else if((A[0] >= A[m-1]) && (B[0] >= B[n-1]))
		{
			offsetA = m - 1;
			offsetB = n - 1;
		}
		else if((A[0] >= A[m-1]) && (B[0] <= B[n-1]))
		{
			offsetA = m - 1;
			offsetB = 0;
		}

		int j = 0;

		while(countA < m || countB < n)
		{
			if(countA == m && countB < n)
			{
				A[j] = B[abs(offsetB - countB)];
				countB++;
				j++;
				continue;
			}
			else if(countB == n && countA < m )
			{
				A[j] = temp[abs(offsetA - countA)];
				countA++;
				j++;
				continue;
			}

			if(temp[abs(offsetA - countA)] <= B[abs(offsetB - countB)])
			{
				A[j] = temp[abs(offsetA - countA)];
				countA ++;
				j++;
			}
			else if(temp[abs(offsetA - countA)] > B[abs(offsetB - countB)])
			{
				A[j] = B[abs(offsetB - countB)];
				countB ++;
				j++;
			}
		}

    }
};