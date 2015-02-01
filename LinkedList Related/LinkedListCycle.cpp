#include "stdafx.h"
#include "LinkList.cpp"

class LinkedListCycle {
public:
    static bool hasCycle(ListNode *head) {

		if(head == nullptr)return false;

		ListNode *slowPtr = head -> next;
		
		if(slowPtr == nullptr)return false;

		ListNode *fastPtr = slowPtr->next;

		while (fastPtr != nullptr)
		{
			if(fastPtr == slowPtr)return true;
			fastPtr = fastPtr ->next;
			if(fastPtr == nullptr)break;
			else fastPtr = fastPtr ->next;
			slowPtr = slowPtr -> next;
		}

		return false;
    }
};