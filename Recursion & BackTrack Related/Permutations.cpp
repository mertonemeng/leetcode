#include "stdafx.h"
#include <vector>

using namespace std;

class Permutations  {
public:
    static vector<vector<int> > permute(vector<int> &num) {
        vector<int> currentPerm;
		vector<vector<int>> result;

		if(num.size() == 0)return result;

		chooseOne(num, currentPerm, result);

		return result;
    }

	static void chooseOne(vector<int> table, vector<int> currentPerm, vector<vector<int>> &result)
	{
		if(table.size() == 0)
		{
			result.push_back(currentPerm);
			return;
		}

		for(int i = 0; i < table.size(); i++)
		{
			vector<int> temp = table;
			currentPerm.push_back(table[i]);
			table.erase(table.begin()+i);
			chooseOne(table, currentPerm, result);
			table = temp;
			currentPerm.pop_back();
		}
	}
};