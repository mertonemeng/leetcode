#include "stdafx.h"
#include <stack>
using namespace std;

class ValidParentheses {
public:
   static bool isValid(string s) {
	   if(s.size() == 0)return true;

		stack<char> parenthesesStk;

        for(int i = 0; i < s.size(); i++)
		{
			switch(s[i])
			{
			case '(':
				parenthesesStk.push(s[i]);
				break;
			case '{':
				parenthesesStk.push(s[i]);
				break;
			case '[':
				parenthesesStk.push(s[i]);
				break;
			case ')':
				if(parenthesesStk.size() == 0)return false;
				if(parenthesesStk.top() != '(')return false;
				else parenthesesStk.pop();
				break;
			case ']':
				if(parenthesesStk.size() == 0)return false;
				if(parenthesesStk.top() != '[')return false;
				else parenthesesStk.pop();
				break;
			case '}':
				if(parenthesesStk.size() == 0)return false;
				if(parenthesesStk.top() != '{')return false;
				else parenthesesStk.pop();
				break;
			default:
				break;
			}
		}

		if(parenthesesStk.size() != 0)return false;
		else return true;
    }
};