#include "stdafx.h"
#include <string>
#include <stack>
using namespace std;

class ValidPalindrome {
public:
   static bool isPalindrome(string s) {
		string temp = "";

		if (s.size() == 0)return true;

		for(int i = 0; i < s.size(); i++)
		{
			if (((s[i]>='0') && (s[i]<='9')) || ((s[i]>='a') && (s[i]<='z')))
			{
				temp += s[i];
			}
			else if ((s[i]>='A') && (s[i]<='Z'))
			{
				temp += (s[i] + (char) 32);
			}
		}
		
		for(int i = 0; i < temp.size(); i++)
		{
			if(temp[i] != temp[temp.size() - i - 1])return false;
		}

		return true;
    }
};