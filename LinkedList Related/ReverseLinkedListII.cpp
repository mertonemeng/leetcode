#include "stdafx.h"
#include "LinkedList.cpp"

class ReverseLinkedListII {
public:
    static ListNode *reverseBetween(ListNode *head, int m, int n) {
		if(head == nullptr)
			return nullptr;
        if(m == n)
			return head;

		if (n < m){
			int temp = n;
			n = m;
			m = temp;
		}

		ListNode *mPre = nullptr, *mPtr = head, *nPtr = head;
		int mCount = 1, nCount = 1;
		bool finishedFlag = false;

		while (!finishedFlag)
		{
			if(mCount < m){
				mPre = mPtr;
				mPtr = mPtr->next;
				mCount++;
			}
			if(nCount < n){
				nPtr = nPtr->next;
				nCount++;
			}
			if(mCount == m && nCount == n){
				if(mPtr == nPtr){
					finishedFlag = true;
					break;
				}
				ListNode *mtemp = mPtr ->next, *ntemp = nPtr->next;
				mPtr ->next = ntemp;
				nPtr ->next = mPtr;
				if(mPre != nullptr)
					mPre ->next = mtemp;
				if(mPtr == head)
					head = mtemp;
				mPtr = mtemp;	
			}
		}

		return head;
	}
};