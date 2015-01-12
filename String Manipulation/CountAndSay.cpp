#include "stdafx.h"
#include <string>
#include <stack>
using namespace std;

class CountAndSay {
public:
	static string countAndSay(int n) {
		string numStr = "1";

		for(int i = 1; i < n; i++)
		{
			numStr = CountAndSay::SayIt(numStr);
		}

		return numStr;
	}

    static string SayIt(string numStr) {
		string result = "";
		char lastdigit = numStr[0];
		int count = 0;

		for(int i = 0; i <= numStr.size(); i++)
		{
			if(i == numStr.size())
			{
				result += (char) (count + 48);
				result += lastdigit;
			}
			else if(lastdigit == numStr[i] && (i < numStr.size()))
			{
				count++;
			}
			else if((lastdigit != numStr[i]) && (i < numStr.size()))
			{
				result += (char) (count + 48);
				result += lastdigit;
				count = 0;
				lastdigit = numStr[i];
				count++;
			}
		}

		return result;
    }
};