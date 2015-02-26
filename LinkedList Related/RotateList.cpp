#include "stdafx.h"
#include "LinkedList.cpp"

using namespace std;

class RotateList {
public:
    static ListNode *rotateRight(ListNode *head, int k) {
		if(head == nullptr)
			return nullptr;

        int length = 1;
		ListNode *ptrEnd = head, *kPtr = head;

		while(ptrEnd->next != nullptr){
			length++;
			ptrEnd = ptrEnd -> next;
		}

		int realK = k%length;

		if(realK == 0)
			return head;

		ptrEnd = head;

		while(ptrEnd->next != nullptr){
			if(realK > 0){
				ptrEnd = ptrEnd->next;
				realK--;
			}
			else{
				kPtr = kPtr->next;
				ptrEnd = ptrEnd->next;
			}
		}

		ListNode *temp = kPtr -> next;
		kPtr -> next = nullptr;
		ptrEnd ->next = head;
		head = temp;

		return head;
    }
};