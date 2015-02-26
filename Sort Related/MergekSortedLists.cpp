#include "stdafx.h"
#include "LinkedList.cpp"
#include <vector>
#include <queue>

using namespace std;

class MergekSortedLists {
public:
	struct GreaterThan{  
		public:
		bool operator() (const ListNode* a, const ListNode* b ){  
			if(a == nullptr)
				return false;
			else if(b == nullptr)
				return true;
			return (a->val > b->val);
		}
	};

    static ListNode *mergeKLists(vector<ListNode *> &lists) {
		if(lists.empty())
			return nullptr;

		priority_queue<ListNode*, vector<ListNode*>, GreaterThan> priQue;

		for(int i = 0; i < lists.size(); i++){
			priQue.push(lists[i]);
		}

		ListNode *head = nullptr;

		while(priQue.top() == nullptr){
			priQue.pop();
			if(priQue.empty()){
				return nullptr;
			} 
		}

		head = priQue.top(); 
		priQue.pop();

		if(head->next != nullptr)
			priQue.push(head->next);

		ListNode *ptr = head;

		while(priQue.size() > 0){
			ListNode *temp = (priQue.top())->next;
			ptr -> next = priQue.top();
			priQue.pop();
			if(temp != nullptr)
				priQue.push(temp);
			ptr = ptr -> next;

		}

		return head;
    }

};