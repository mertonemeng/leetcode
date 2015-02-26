#include "stdafx.h"
#include "LinkedList.cpp"


class SwapNodesinPairs  {
public:
    static ListNode *swapPairs(ListNode *head) {

		if(head == nullptr)return nullptr;
		if(head ->next == nullptr)return head;

		ListNode *node1 = head, *node2 = head->next;
		ListNode *temp = nullptr; 

		temp = node2 ->next;
		node1->next = temp;
		node2->next = node1;
		head = node2;

		if(temp == nullptr)return head;

		node1 = node1->next;
		node2 = node1 ->next;
		if(node2 == nullptr)return head;

		ListNode *pred = head->next;

		while(node2 != nullptr)
		{
			temp = node2 ->next;
			node1->next = temp;
			node2->next = node1;
			pred->next = node2;
			pred = node1;
			node1 = node1 -> next;
			if(node1 == nullptr)break;
			node2 = node1 -> next;
		}

		return head;
    }
};