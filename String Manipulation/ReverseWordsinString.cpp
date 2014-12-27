#include "stdafx.h"
#include <stack>
#include <string>

using namespace std;

class ReverseWordsinString {
public:
    static void reverseWords(string &s) 
    {
    	stack<string> stk;
    	int pos = 0, last_pos = 0;
    
    	do
    	{
    		pos = s.find(' ', last_pos);
    		string temp = s.substr(last_pos,pos - last_pos);
    		if(temp != "")stk.push(temp);
    		last_pos = pos + 1;
    	}
    	while(s.find(' ', pos) != string::npos);
    
    	s.clear();
    
		while(stk.size() > 0)
		{
			string temp = stk.top();

			if(stk.size() == 1)s += temp;
			else s += temp + " ";

			stk.pop();
		}
    }
};