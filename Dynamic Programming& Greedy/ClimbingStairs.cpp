#include "stdafx.h"

using namespace std;

class ClimbingStairs {
public:
    static int climbStairs(int n) {
		int cache[3] = {1, 1, 0};

		for(int i = 2;i < n;i++){
			cache[i%3] = cache[(i - 1)%3] + cache[(i - 2)%3];
		}

		return cache[(n-1)%3];
    }
};