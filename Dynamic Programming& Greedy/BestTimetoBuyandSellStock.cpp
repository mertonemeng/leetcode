#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class BestTimetoBuyandSellStock {
public:
    static int maxProfit(vector<int> &prices) {
		int n = prices.size();

		if(n == 0){
            return 0;
        }

		int profit[2] = {INT_MIN, INT_MIN};
		int minPrice = prices[0];

		profit[0] = 0;

		for(int i = 1; i < n; i++){
			minPrice = minPrice > prices[i]? prices[i]: minPrice;
			profit[i%2] = profit[(i-1)%2]> (prices[i] - minPrice)?profit[(i-1)%2] : (prices[i] - minPrice);
		}

		return profit[(n - 1)%2];
    }
};