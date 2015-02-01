#include "stdafx.h"
#include "LinkList.cpp"

class AddTwoNumbers{
public:
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		int carryFlag = 0;
		ListNode *resultHead = nullptr;
		ListNode *ptr1 = nullptr, *ptr2 = nullptr, *ptr3 = nullptr;
		
		if (l1 == nullptr)return l2;
		else if (l2 == nullptr)return l1;

		ptr1 = l1;
		ptr2 = l2;
		
		if(l1->val + l2->val < 10)
		{
			resultHead = new ListNode(l1->val + l2->val);
		}
		else
		{
			resultHead = new ListNode((l1->val + l2->val)%10);
			carryFlag = 1;
		}

		ptr1 = ptr1 ->next;
		ptr2 = ptr2 ->next;
		ptr3 = resultHead;

		while(ptr1 != nullptr || ptr2 != nullptr)
		{
			if(ptr1 != nullptr && ptr2 != nullptr)
			{
				if(ptr1->val + ptr2->val + carryFlag < 10)
				{
					ptr3->next = new ListNode(ptr1->val + ptr2->val + carryFlag);
					carryFlag = 0;
				}
				else
				{
					ptr3->next = new ListNode((ptr1->val + ptr2->val + carryFlag)%10);
					carryFlag = 1;
				}
				ptr1 = ptr1 -> next;
				ptr2 = ptr2 -> next;
			}
			else if(ptr1 != nullptr && ptr2 == nullptr)
			{
				if(ptr1->val + carryFlag < 10)
				{
					ptr3->next = new ListNode(ptr1->val + carryFlag);
					carryFlag = 0;
				}
				else
				{
					ptr3->next = new ListNode((ptr1->val + carryFlag)%10);
					carryFlag = 1;
				}
				ptr1 = ptr1 -> next;
			}
			else if(ptr1 == nullptr && ptr2 != nullptr)
			{
				if(ptr2->val + carryFlag < 10)
				{
					ptr3->next = new ListNode(ptr2->val + carryFlag);
					carryFlag = 0;
				}
				else
				{
					ptr3->next = new ListNode((ptr2->val + carryFlag)%10);
					carryFlag = 1;
				}
				ptr2 = ptr2 -> next;
			}

			ptr3 = ptr3 -> next;
		}

		if(carryFlag > 0)ptr3 -> next = new ListNode(1);

		return resultHead;
    }
};