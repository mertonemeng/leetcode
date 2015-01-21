#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class LetterCombinationsofaPhoneNumber {
public:
    static vector<string> letterCombinations(string digits) {
		string currentStr = "";
		long int count = 0;
		vector<string> possibleStringTab;

		if(digits!="")getNextDigit(digits, count, currentStr, possibleStringTab);
		else possibleStringTab.push_back("");
		return possibleStringTab;
		
    }

	static void getNextDigit(string digits, long int count, string currentStr, vector<string> &table)
	{
		string phoneNumTable[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		int digit = (int) (digits[count]-48);

		for(int i = 0; i < phoneNumTable[digit].size();i++)
		{
			string temp = currentStr;
			if(count == digits.size()-1)
			{
				table.push_back(currentStr + phoneNumTable[digit][i]);
			}
			else
			{
				currentStr += phoneNumTable[digit][i];
				getNextDigit(digits, count + 1, currentStr, table);
			}
			currentStr = temp;
		}
		return;
	}
};