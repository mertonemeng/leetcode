#include "stdafx.h"
#include "LinkList.cpp"

using namespace std;

class MergeTwoSortedLists  {
public:
    static ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *resultHead = nullptr;
		ListNode *ptr = resultHead;

		if(l1 == nullptr && l2 != nullptr)
		{
			resultHead = l2;
			l2 = l2->next;
		}
		else if(l1 != nullptr &&l2 == nullptr)
		{
			resultHead = l1;
			l1 = l1->next;
		}
		else if(l1 != nullptr && l2 != nullptr)
		{
			resultHead = l1->val > l2->val?l2:l1;
			l1 = resultHead == l1?l1->next:l1;
			l2 = resultHead == l2?l2->next:l2;
		}
		else
		{
			return nullptr;
		}

		ptr = resultHead;

		while(l1 != nullptr || l2 != nullptr)
		{
			if(l1 != nullptr && l2 != nullptr)
			{
				if(l1 -> val < l2-> val)
				{
					ptr->next = l1;
					l1 = l1->next;
					ptr = ptr->next;
					
				}
				else
				{
					ptr->next = l2;
					l2 = l2->next;
					ptr = ptr->next;
					
				}
			}
			else if(l1 == nullptr && l2 != nullptr)
			{
				ptr->next = l2;
				l2 = l2->next;
				ptr = ptr->next;
				
			}
			else if(l1 != nullptr && l2 == nullptr)
			{
				ptr->next = l1;
				l1 = l1->next;
				ptr = ptr->next;
			}
		}

		return resultHead;
    }
};