#include "stdafx.h"
#include "LinkedList.cpp"

class PartitionList {
public:
   static ListNode *partition(ListNode *head, int x) {

		if(head == nullptr)return nullptr;
		if(head ->next == nullptr)return head;

		ListNode *endPtr = head;

		while(endPtr->next != nullptr){
			endPtr = endPtr->next;
		}

		ListNode *prePtr = nullptr, *ptr = head, *lastPtr = endPtr;
		bool fisrtMoveFlag = true;
		while(1){
			if(ptr->val < x){
				prePtr = ptr;
				ptr = ptr->next;
			}
			else{
				if(ptr != head){
					prePtr ->next = ptr ->next;
					ptr ->next = nullptr;
					lastPtr -> next = ptr;
					ptr = prePtr ->next;
					lastPtr = lastPtr ->next;
				}
				else{
					ListNode *temp = ptr->next;
					lastPtr -> next = ptr;
					ptr ->next = nullptr;
					head = temp;
					ptr = temp;
					lastPtr = lastPtr ->next;
				}
				if(fisrtMoveFlag){
					endPtr = endPtr -> next;
					fisrtMoveFlag = false;
				}
			}
			if(ptr == endPtr)
				break;
		}

		return head;
    }
};