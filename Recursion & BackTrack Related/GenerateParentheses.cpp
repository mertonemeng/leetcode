#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;

class GenerateParentheses {
public:
    static vector<string> generateParenthesis(int n) {
		vector<string> result;
        string currenStr = "";
		int leftCount = 0, rightCount = 0;
		
		backTrack(result, currenStr, '(', leftCount, rightCount, n);

		return result;
    }

	static void backTrack(vector<string> &result, string currenStr, char parChar,  int leftCount, int rightCount, int n)
	{
		if(parChar == '(')
		{
			currenStr += parChar;
			leftCount++;
		}
		if(parChar == ')')
		{
			currenStr += parChar;
			rightCount++;
		}

		if(leftCount < n)backTrack(result, currenStr,'(', leftCount, rightCount, n);
		if(rightCount < leftCount)backTrack(result, currenStr,')', leftCount, rightCount, n);
		if(leftCount + rightCount >= 2*n)
		{
			result.push_back(currenStr);
			return;
		}
	}
};