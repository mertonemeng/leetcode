#include "stdafx.h"
#include <stack>
#include <vector>

using namespace std;

class LargestRectangleinHistogram{
	public:
    static int largestRectangleArea(vector<int> &height) {
       
        if(height.empty()){
            return 0;
        }
        
		int maxArea = 0;
		stack<int> histStk;
		int i = 0;
		height.push_back(0);

		while(i < height.size()){

			if(histStk.empty() || height[i] >= height[histStk.top()]){
				histStk.push(i);
				i++;
			} else{
				int temp = histStk.top();
				histStk.pop();
				if(!histStk.empty()){
					maxArea = maxArea > height[temp]*(i - histStk.top() - 1) ? maxArea : height[temp]*(i - histStk.top() - 1);
				} else{
					maxArea = maxArea > height[temp]*i ? maxArea : height[temp]*i;
				}
			}
		}

		return maxArea;
    }
};