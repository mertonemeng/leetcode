#include "stdafx.h"
#include <stack>

using namespace std;

class MinStack {
private:
	stack<int> stk;
	stack<int> minNumStack;
public:
    void push(int x) {
		stk.push(x);
		if(!minNumStack.size() || minNumStack.top() >= x)
		{
			minNumStack.push(x);
		}
    }

    void pop() {
        if(!stk.empty()) {
            if(!minNumStack.empty() && stk.top() == minNumStack.top())
                minNumStack.pop();
            stk.pop();
        }
    }

    int top() {
		if(!stk.empty())return stk.top();
    }

    int getMin() {
		if(!stk.empty())return minNumStack.top();
    }
};