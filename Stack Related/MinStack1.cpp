#include "stdafx.h"

class MinStack {
private:
	struct StackElem
	{
		int val;
		StackElem *next;
	};

	StackElem *topPtr;

public:
	MinStack()
	{
		topPtr = nullptr;
	}

    void push(int x) {
		StackElem *newElem = new StackElem;
		if(topPtr!= nullptr)newElem->next = topPtr;
		else newElem->next = nullptr;
		newElem->val = x;
		topPtr = newElem;
    }

    void pop() {
		StackElem *tempPtr = topPtr->next;
		delete topPtr;
		if (tempPtr == nullptr)
		{
			topPtr = nullptr;
			return;
		}
		topPtr = tempPtr;
    }

    int top() {
		return topPtr->val;
    }

    int getMin() {
		int minimumVal = topPtr->val;
		StackElem *tempPtr = topPtr;
		while(tempPtr != nullptr)
		{
			if (minimumVal > (tempPtr->val))
			{
				minimumVal = tempPtr->val;
			}
			tempPtr = tempPtr->next;
		}

		return minimumVal;
    }
};