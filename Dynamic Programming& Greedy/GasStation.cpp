#include "stdafx.h"
#include <vector>
using namespace std;

class GasStation {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int totalIncome = 0;

		if(gas.empty())
			return 0;

		for(int i = 0; i < gas.size();i++){
			totalIncome += (gas[i] - cost[i]);
		}

		if(totalIncome < 0)
			return -1;
		
		for(int i = 0; i < gas.size();i++){
			if(totalIncome >= 0 &&  (gas[i] - cost[i]) > 0)
				return i;
			else{
				totalIncome -= (gas[i] - cost[i]);
			}
		}
    }
};