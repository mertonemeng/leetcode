#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class ThreeSumClosest {
public:
    static int threeSumClosest(vector<int> &num, int target) {
		int closetNum = INT_MAX;
		int result = 0;

		if(num.size() == 0)
			return 0;

		sort(num.begin(), num.end());

        for(int i = 0; i < num.size();i ++){

			int start = i + 1;
			int end = num.size() - 1;

			while(start < end){
				int temp = num[i] + num[start] + num[end];
				if(temp > target){
					end--;
				}
				if(temp < target){
					start++;
				}
				if(temp == target){
					return temp;
				}
				if(abs(target - temp) < closetNum){
					closetNum = abs(target - temp);
					result = temp;
				}
			}
		}

		return result;
    }
};