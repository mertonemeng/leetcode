#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size();
		if(n == 0){
			return 0;
		}
		int start = 0;
		int end = n - 1;
		int maxS = 0;

		while(start < end){
			int bottom = end - start;

			if(height[start] < height[end]){
				maxS = maxS < height[start]*bottom ? height[start]*bottom : maxS;
				start++;
			} else{
				maxS = maxS < height[end]*bottom ? height[end]*bottom : maxS;
				end--;
			}
		}

		return maxS;
    }
};