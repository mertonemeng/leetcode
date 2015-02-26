#include "stdafx.h"
#include "LinkedList.cpp"

class SortList {
public:
    static ListNode *sortList(ListNode *head) {

		if (head == nullptr || head->next == nullptr) {
            return head;
        }

		ListNode* midPtr = findMiddle(head);

		ListNode* right = sortList(midPtr->next);
		midPtr->next = nullptr;
		ListNode* left = sortList(head);

		return Merge(left, right);
    }

	static ListNode* findMiddle(ListNode *head){
		ListNode*midPtr = head, *endPtr = head -> next;

		while((endPtr != nullptr) && (endPtr->next != nullptr)){
			endPtr = endPtr ->next->next;
			midPtr = midPtr ->next;
		}

		return midPtr;
	}

	static ListNode *Merge(ListNode *head1, ListNode *head2)
	{
		ListNode *dummy = new ListNode(0);
		ListNode *tail = dummy;

		while((head1 != nullptr) && (head2 != nullptr)){
			if(head1 ->val < head2 ->val){
				tail ->next = head1;
				head1 = head1 ->next;
			} else{
				tail ->next = head2;
				head2 = head2 ->next;
			}
			tail = tail -> next;
		}
		if(head1 != nullptr){
			tail ->next = head1;
		}else {
			tail ->next = head2;

		}

		return dummy -> next;
	}

};