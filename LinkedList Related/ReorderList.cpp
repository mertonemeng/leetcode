#include "stdafx.h"
#include "LinkedList.cpp"

class ReorderList {
public:
    static void reorderList(ListNode *head) {
		ListNode *endPtr = head, *halfPtr = head, *preHalfPtr = nullptr;

		if(head == nullptr)
			return;

		if(head -> next == nullptr)
			return;

		//Find the Mid-point

		while(endPtr ->next != nullptr){
			endPtr = endPtr -> next;
			if(endPtr ->next == nullptr)
				break;
			else
				endPtr = endPtr -> next;
			preHalfPtr = halfPtr;
			halfPtr = halfPtr -> next;
		}

		halfPtr = halfPtr -> next;
		preHalfPtr = preHalfPtr -> next ;
		preHalfPtr -> next = nullptr;

		//Reverse the Second half

		while(halfPtr != endPtr){
			ListNode *temp1 = endPtr ->next, *temp2 = halfPtr ->next;
			endPtr ->next = halfPtr;
			halfPtr ->next = temp1;
			halfPtr = temp2;
		}

		//Merge Together
		ListNode *startPtr = head, *newPtr = head;
		while(newPtr != nullptr && startPtr != nullptr){
			ListNode *temp1 = startPtr ->next, *temp2 = (endPtr == nullptr) ? nullptr:endPtr ->next;
			if(newPtr != head)
				newPtr ->next = startPtr;
			startPtr ->next = endPtr;
			newPtr = endPtr;
			startPtr = temp1;
			endPtr = temp2;
		}
    }
};