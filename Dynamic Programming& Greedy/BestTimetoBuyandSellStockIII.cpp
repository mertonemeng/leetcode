#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class BestTimetoBuyandSellStockIII {
public:
    static int maxProfit(vector<int> &prices) {
		int n = prices.size();

		if(n == 0 || n == 1){
			return 0;
		}

		vector<int> lMaxProfit(n, 0);
		vector<int> rMaxProfit(n, 0);

		int rMax = prices[n - 1];
		int lMin = prices[0];
		int maxProfit = INT_MIN;

		for(int i = 1; i < n; i++){
			if(lMin > prices[i]){
				lMin = prices[i];
			}
			lMaxProfit[i] = max(lMaxProfit[i - 1], prices[i] - lMin);
		}

		for(int i = n - 2; i > 0; i--){
			if(rMax < prices[i]){
				rMax = prices[i];
			}
			rMaxProfit[i] = max(rMaxProfit[i + 1], rMax - prices[i]);
		}

		for(int i = 0; i < n; i++){
			maxProfit = max(maxProfit, lMaxProfit[i] + rMaxProfit[i]);
		}

		return maxProfit;
    }
};