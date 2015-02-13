#include "stdafx.h"
#include "LinkedList.cpp"

class InsertionSortList {
public:
    static ListNode *insertionSortList(ListNode *head) {
		if(head == nullptr)return nullptr;
		if(head->next == nullptr)return head;

		ListNode *predPtr = head, *ptr = head->next;

		if(ptr -> val < predPtr -> val)
		{
			ListNode *temp = ptr->next;
			ptr->next = predPtr;
			predPtr ->next = temp;
			head = ptr;
		}

		predPtr = head;
		ptr = head->next;

		ListNode *pSearchPred = head, *pSearch = head->next;

		while(ptr != nullptr)
		{
			while(predPtr != pSearchPred)
			{
				if((ptr->val >= pSearchPred ->val) && (ptr->val <= pSearch->val))
				{
					ListNode *temp = ptr ->next;
					pSearchPred->next = ptr;
					ptr ->next = pSearch;
					predPtr->next = temp;
					break;
				}
				if((ptr->val <= pSearchPred ->val) && (pSearchPred == head))
				{
					ListNode *temp = ptr ->next;
					ptr ->next = pSearchPred;
					predPtr->next = temp;
					head = ptr;
					break;
				}
				pSearchPred = pSearchPred->next;
				pSearch = pSearch -> next;

			}
			pSearchPred = head;
			pSearch = head->next;
			if(predPtr->next != ptr)
			{
				ptr = predPtr -> next;
			}
			else
			{
				predPtr = predPtr->next;
				ptr = ptr -> next;
			}
		}

		return head;
    }
};