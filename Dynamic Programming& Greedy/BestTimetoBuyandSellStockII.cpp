#include "stdafx.h"
#include <vector>

using namespace std;

class BestTimetoBuyandSellStock {
public:
	int maxProfit(vector<int> &prices) {
		int n = prices.size();

		if(n == 0){
			return 0;
		}

        int maximum = 0;
		int buyPrice = prices[0];
		for(int i = 1; i < n; i++){
			if(prices[i - 1] > prices[i]){
				maximum += prices[i - 1] - buyPrice;
				buyPrice = prices[i];
			}
		}

		if(buyPrice <= prices[n - 1]){
			maximum += prices[n - 1] - buyPrice;
		}

		return maximum;
    }
};