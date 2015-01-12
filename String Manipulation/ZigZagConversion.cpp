#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

class ZigZagConversion {
public:
	static string convert(string s, int nRows) {
		string result = "";
		vector<string> strVector;
		bool isTurnAround = false;
		int zigZagCount = 0;

		for(int i = 0; i < nRows; i++)
		{
			strVector.push_back("");
		}

		for(int i = 0; i < s.size(); i++)
		{
			if (!isTurnAround)
			{
				strVector[zigZagCount] += s[i];
				zigZagCount++;
			}
			else
			{
				strVector[zigZagCount] += s[i];
				zigZagCount--;
			}

			if(zigZagCount == nRows)
			{
				isTurnAround = true;
				if(nRows == 1) zigZagCount = 0;
				else zigZagCount = nRows - 2;

			}
			else if(zigZagCount == -1)
			{
				isTurnAround = false;
				if(nRows == 1) zigZagCount = 0;
				else zigZagCount = 1;
			}
		}

		for (int i = 0; i < nRows; i++)
		{
			result += strVector[i];
		}
		
		return result;
    }
};