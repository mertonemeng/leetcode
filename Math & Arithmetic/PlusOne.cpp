#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class PlusOne {
public:
    static vector<int> plusOne(vector<int> &digits) {

		digits.at(digits.size()-1) = digits.at(digits.size()-1) + 1;
		if(digits.at(digits.size()-1) == 10)
		{
			digits.at(digits.size()-1) = 0;
			for(int i = 1; i < digits.size(); i++)
			{
				digits.at(digits.size()-1-i) = digits.at(digits.size()-1-i) + 1;
				if(digits.at(digits.size()-1-i) == 10)
				{
					digits.at(digits.size()-1-i)  = 0;
					if((digits.size()-1-i) == 0)
					{
						digits.insert(digits.begin(),1);
						break;
					}
					continue;
				}
				else
				{
					break;
				}
			}
			if ((digits.size()-1) == 0)
			{
				digits.insert(digits.begin(),1);
			}
		}

		return digits;
    }
};