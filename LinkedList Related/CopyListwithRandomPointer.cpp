#include "stdafx.h"
#include <unordered_map>

using namespace std;

 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };
 

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

		if(head == nullptr)
			return nullptr;

        unordered_map<RandomListNode *, RandomListNode *> hashTable;
		RandomListNode *ptr = head ->next;
		RandomListNode *newHead = new RandomListNode(*head);
		RandomListNode *tail = newHead;

		hashTable[head] = newHead;

		while(ptr != nullptr){
			tail -> next = new RandomListNode(*ptr);
			tail = tail->next;
			hashTable[ptr] = tail;
			ptr = ptr ->next;
		}

		tail = newHead;
		ptr = head;

		while(ptr != nullptr){
			tail ->random = hashTable[ptr ->random];
			tail = tail ->next;
			ptr = ptr ->next;
		}

		return newHead;
    }
};