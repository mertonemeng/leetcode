#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class MaximumSubarray {
public:
	static int maxSubArray(int A[], int n) {

		if(n == 0){
			return 0;
		}

		vector<int > sumArr(n + 1, 0); 
		
		int maximum = INT_MIN;

		for(int i = 1; i < n+1; i++){
			sumArr[i] = sumArr[i - 1] + A[i-1];
		}

		int minimum = sumArr[0];

		for(int i = 1; i <= n; i++){
			maximum = maximum < sumArr[i] - minimum? sumArr[i] - minimum: maximum;
			minimum = minimum > sumArr[i]? sumArr[i]:minimum;
			
		}

		return maximum;
    }
};