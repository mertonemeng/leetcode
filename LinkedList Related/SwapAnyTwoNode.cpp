#include "stdafx.h"
#include "LinkedList.cpp"

class Solution {
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

		ListNode *nPre = nullptr, *mPre = nullptr, *mPtr = head, *nPtr = head;
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
				nPre = nPtr;
				nPtr = nPtr->next;
				nCount++;
			}
			if(mCount == m && nCount == n){
				if(nPre != mPtr){
					ListNode *mtemp = mPtr ->next, *ntemp = nPtr->next;
					nPtr->next = mtemp;
					mPtr->next = ntemp;
					if(nPre != nullptr)
						nPre ->next = mPtr;
					else
						head = mPtr;

					if(mPre != nullptr)
						mPre ->next = nPtr;
					else
						head = nPtr;

					finishedFlag = true;
				}
				else{
					ListNode *ntemp = nPtr->next;
					nPtr->next = mPtr;
					mPtr->next = ntemp;
					if(mPre != nullptr)
						mPre ->next = nPtr;
					else
						head = nPtr;
					finishedFlag = true;
				}
			}
		}

		return head;
    }
};