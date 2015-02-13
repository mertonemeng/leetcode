#include "stdafx.h"
#include "LinkedList.cpp"
#include <stack>
class RemoveDuplicatesfromSortedListII {
public:
	static ListNode *deleteDuplicates(ListNode *head) {

		deque<int> que;

		if(head == nullptr)return nullptr;
		if(head -> next == nullptr)return head;

		int replicateNum = head->val;
		ListNode *pred = head, *ptr = head->next;

		while(ptr != nullptr)
		{
			if(ptr -> val == replicateNum)
			{
				ListNode *temp = ptr->next;
				if(que.size() == 0)que.push_back(ptr->val);
				else if((que.size()>0) && (replicateNum != que.back()))que.push_back(ptr->val);
				delete ptr;
				pred->next = temp;
				ptr = temp;
				if(ptr == nullptr)break;
			}
			if(ptr -> val != replicateNum)
			{
				replicateNum = ptr->val;
				pred = ptr;
				ptr = ptr->next;
			}
		}

		pred = head;
		ptr = head->next;

		if(ptr == nullptr)
		{
			if(pred -> val == que.front())
			{
				delete pred;
				return nullptr;
			}
		}

		while(que.size() > 0)
		{
			if(head->val == que.front())
			{
				ListNode *temp = head -> next;
				delete head;
				head = temp;
				pred = head;
				if(head != nullptr)ptr = head->next;
				que.pop_front();
				continue;
			}
			if(ptr -> val == que.front())
			{
				ListNode *temp = ptr->next;
				delete ptr;
				pred->next = temp;
				ptr = temp;
				que.pop_front();
				continue;
			}
			if(ptr -> val != que.front())
			{
				pred = ptr;
				ptr = ptr->next;
			}
		}

		return head;
    }
};