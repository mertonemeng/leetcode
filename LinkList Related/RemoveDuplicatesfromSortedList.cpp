#include "stdafx.h"
#include "LinkList.cpp"

using namespace std;

class RemoveDuplicatesfromSortedList  {
public:
    static ListNode *deleteDuplicates(ListNode *head) {

		if (head == nullptr)return nullptr;

		ListNode *ptr = head->next;
		ListNode *lastvalue = head;

		while (ptr != nullptr)
		{
			if(lastvalue ->val != ptr ->val)
			{
				lastvalue = ptr;
				ptr = ptr->next;
			}
			else
			{
				ListNode *temp = ptr->next;
				delete ptr;
				ptr = temp;
				lastvalue ->next = ptr;
			}
		}

		return head;
    }
};