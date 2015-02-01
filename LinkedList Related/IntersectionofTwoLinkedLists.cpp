#include "stdafx.h"
#include "LinkList.cpp"

class IntersectionofTwoLinkedLists {
public:
    static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		long int countA = 0, countB = 0;
		long int delaycount = 0;
		ListNode* ptrA = headA, *ptrB = headB;
		ListNode* result = nullptr;

		if(headA == nullptr || headB == nullptr)return nullptr;
		if(headA == headB)return headA;

		while(ptrA ->next != nullptr)
		{
			ptrA = ptrA->next;
			countA ++;
		}

		while(ptrB ->next != nullptr)
		{
			ptrB = ptrB->next;
			countB ++;
		}

		if(ptrA != ptrB)return nullptr;
		
		delaycount = countA - countB;

		ptrA = headA;
		ptrB = headB;

		while(ptrA != nullptr || ptrB != nullptr)
		{
			if(delaycount > 0)
			{
				ptrA = ptrA->next;
				delaycount--;
			}
			else if(delaycount < 0)
			{
				ptrB = ptrB->next;
				delaycount++;
			}
			else
			{
				if(ptrB == ptrA)
				{
					result = ptrA;
					break;
				}
				ptrB = ptrB->next;
				ptrA = ptrA->next;
			}
		}

		return result;
    }
};