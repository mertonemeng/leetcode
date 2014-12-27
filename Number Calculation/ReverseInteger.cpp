#include "stdafx.h"
#include <stack>
#include <string>

using namespace std;

class ReverseInteger {
public:
	public:
    static int reverse(int x) {
        deque<int> que;
	    int quotient = abs(x);
	    int val = 0;

	    int sign = (x>=0)?1:-1;

    	do
    	{
    		que.push_back(quotient%10);
    		quotient = quotient/10;
    	}
    	while (quotient > 0);
    
    	int e = 1;

    	while (que.size() > 0)
    	{
    		val+= e*que.back();
    		que.pop_back();
    		e *= 10;
    	}

	    return sign * val;
    }
};