#include "stdafx.h"
#include "LinkList.cpp"

class RemoveNthNodeFromEndofList {
public:
    static ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *ptrEnd = head, *ptrNthPt = head;
		ListNode *temp = nullptr;
		int count = 0;

		if(head == nullptr)return nullptr;

		while (ptrEnd != nullptr)
		{
			if(count <= n)count++;
			else ptrNthPt = ptrNthPt ->next;

			ptrEnd = ptrEnd->next;
		}

		if(count == n)
		{
			head = head ->next;
			delete ptrNthPt;
			return head;
		}

		if(ptrNthPt->next == nullptr) 
		{
			delete ptrNthPt;
			return nullptr;
		}

		temp = ptrNthPt->next -> next;
		delete ptrNthPt->next;
		ptrNthPt ->next = temp;

		return head;

    }
};