#include "stdafx.h"
#include <vector>
#include <climits>
using namespace std;

class JumpGameII {
public:
	//Version 1 DP

    static int jump(int A[], int n) {
		if(n == 0)
			return true;

		vector<int>cache(n, 0);

		for(int i = 1; i < n; i++){
			int minStep = INT_MAX;
			for(int j = 0; j < i; j++){
				 if(j + A[j] >= i){
					 minStep = minStep > cache[j]?cache[j]:minStep;
				 }
			}
			cache[i] = minStep + 1;
		}

		return cache[n - 1];
    }

	//Version 2 Greedy

	static bool jumpGreedy(int A[], int n){

		if(n == 0){
			return 0;
		}

		int maxReachPos = A[0];
		int curMaxReachPos = A[0];
		int curStep = 1;

		for(int i = 1; i <= min(n, maxReachPos); i++){
			curMaxReachPos = max(curMaxReachPos, i + A[i]);
			if(i == n - 1){
				return curStep;
			}
			if(i == maxReachPos){
				maxReachPos = curMaxReachPos;
				curStep++;
			}
		}

		return 0;
	}
};