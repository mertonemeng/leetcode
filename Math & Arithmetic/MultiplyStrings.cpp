#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class MultiplyStrings {
public:
	static string multiply(string num1, string num2) {
        int carryDigit = 0;
		int tempDigit = 0;
		string result = "";
		vector<string> tempVec;
		//multiply the string

		string trailingZero = "";

		if(num1.size() == 1 && num1[0] == '0')return "0";
		if(num2.size() == 1 && num2[0] == '0')return "0";

		for(int i = 0; i < num1.size(); i++)
		{
			string tempResult = "";
			tempDigit = (int)(num1[num1.size() - 1 - i] - 48);
			for(int j = 0; j < num2.size(); j++)
			{
				int temp = (int)(num2[num2.size() - 1 - j] - 48) * tempDigit + carryDigit;
				carryDigit = temp/10;
				temp = temp%10;

				tempResult = (char) (temp + 48) + tempResult;
			}
			if (carryDigit > 0)tempResult = (char)(carryDigit + 48) + tempResult;
			tempVec.push_back(tempResult+trailingZero);
			trailingZero += '0';
			carryDigit = 0;
		}

		carryDigit = 0;
		string tempResult = tempVec[0];

		for(int j = 1; j < tempVec.size(); j++)
		{
			string tempStr = "";

			for(int i = 0; i < tempVec[j].size(); i++)
			{
				int temp = 0;
				if(i < tempVec[j].size() && i < tempResult.size())
				{
					temp = (int)(tempVec[j][tempVec[j].size()-i-1]-48) + (int)(tempResult[tempResult.size() - 1 - i]-48) + carryDigit;
				}
				else if(i < tempVec[j].size() && i >= tempResult.size())
				{
					temp = (int)(tempVec[j][tempVec[j].size()-i-1]-48) + carryDigit;
				}
				else if(i >= tempVec[j].size() && i < tempResult.size())
				{
					temp = (int)(tempResult[tempResult.size()-1-i]-48) + carryDigit;
				}
				carryDigit = temp/10;
				temp %= 10;

				tempStr = (char) (temp + 48) + tempStr;

			}
			if(carryDigit > 0)tempStr = (char)(carryDigit+48) + tempStr;

			tempResult = tempStr;
			carryDigit = 0;
		}
		

		return tempResult;
    }
};