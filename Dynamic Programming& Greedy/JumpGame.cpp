#include "stdafx.h"
#include <vector>

using namespace std;

class JumpGame {
public:
	//Version 1 DP

    static bool canJump(int A[], int n) {
		if(n == 0)
			return true;

		vector<bool>cache(n, false);

		cache[0] = true;

		for(int i = 1; i < n; i++){
			bool temp = false;
			for(int j = 0; j < i; j++){
				 temp = temp || (cache[j] && ((j + A[j])> i));
			}
			cache[i] = temp;
		}

		return cache[n - 1];
    }

	//Version 2 Greedy

	static bool canJumpGreedy(int A[], int n){
		if(n == 0)
			return true;
		int lastPos = n - 1;


		for(int i = n -1; i >= 0; i--){
			if(A[i] + i > lastPos){
				lastPos = i;
			}
		}

		if(lastPos == 0)
			return true;
		else
			return false;
	}
};