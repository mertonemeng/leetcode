#include "stdafx.h"
#include "LinkList.cpp"

class LinkedListCycleII {
public:
    static ListNode *detectCycle(ListNode *head) {
		int cycleCount = 0;
		ListNode *cycleJoint = head;

       if(head == nullptr)return nullptr;

		ListNode *slowPtr = head -> next;
		
		if(slowPtr == nullptr)return nullptr;

		ListNode *fastPtr = slowPtr->next;

		while (fastPtr != nullptr)
		{
			if(fastPtr == slowPtr)break;
			cycleCount++;
			fastPtr = fastPtr ->next;
			if(fastPtr == nullptr)return nullptr;
			else fastPtr = fastPtr ->next;
			slowPtr = slowPtr -> next;
		}

		if(fastPtr == nullptr)return nullptr;

		ListNode *p = head ->next;

		while (p != cycleJoint)
		{
			if(cycleCount > 0)
			{
				cycleCount--;
			}
			else
			{
				cycleJoint = cycleJoint->next;
			}
			p = p->next;
		}

		return cycleJoint;
    }
};