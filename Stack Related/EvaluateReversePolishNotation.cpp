#include "stdafx.h"
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

class EvaluateReversePolishNotation {
public:
    static int evalRPN(vector<string> &tokens) {
        stack<string> numStack;
		int result = 0;
		stringstream ss;

		if(tokens.size() == 0)return 0;
		if(tokens.size() == 1)
		{
			ss<<tokens[0];
			ss>>result;
			return result;
		}

		for(int i = 0; i < tokens.size(); i++)
		{
			stringstream resultStr;
			int op1 = 0, op2 = 0;
			numStack.push(tokens[i]);
			if(!isNumber(numStack.top()))
			{
				switch(numStack.top()[0])
				{
					case '+':
						numStack.pop();
						ss<<numStack.top();
						ss>>op2;
						ss.clear();
						numStack.pop();
						ss<<numStack.top();
						ss>>op1;
						ss.clear();
						numStack.pop();
						result = op1 + op2;
						resultStr<<result;
						numStack.push(resultStr.str());
						resultStr.clear();
						break;
					case '-':
						numStack.pop();
						ss<<numStack.top();
						ss>>op2;
						ss.clear();
						numStack.pop();
						ss<<numStack.top();
						ss>>op1;
						ss.clear();
						numStack.pop();
						result = op1 - op2;
						resultStr<<result;
						numStack.push(resultStr.str());
						resultStr.clear();
						break;
					case '*':
						numStack.pop();
						ss<<numStack.top();
						ss>>op2;
						ss.clear();
						numStack.pop();
						ss<<numStack.top();
						ss>>op1;
						ss.clear();
						numStack.pop();
						result = op1 * op2;
						resultStr<<result;
						numStack.push(resultStr.str());
						resultStr.clear();
						break;
					case '/':
						numStack.pop();
						ss<<numStack.top();
						ss>>op2;
						ss.clear();
						numStack.pop();
						ss<<numStack.top();
						ss>>op1;
						ss.clear();
						numStack.pop();
						result = op1 / op2;
						resultStr<<result;
						numStack.push(resultStr.str());
						resultStr.clear();
						break;
					default:
						break;
				}
			}
		}

		return result;
    }

	static bool isNumber(string s)
	{
		if(s[0] >= '0' && s[0] <= '9')return true;
		else if(s[0] == '-')
		{
			if(s.size() == 1)return false;
			else return true;
		}
		else return false;
	}
};