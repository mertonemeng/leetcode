#include "stdafx.h"
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache{
private:
	struct ListNode {
		int key;
		int value;
		ListNode *next;
		ListNode *previous;
		ListNode(int x, int y) : key(x), value(y), next(NULL), previous(NULL) {}
	};

	int cacheCapacity;
	ListNode *head, *tail;
	unordered_map<int, ListNode*> hashTable;

public:
    LRUCache(int capacity) {
        cacheCapacity = capacity;
    }
    
    int get(int key) {

		if(hashTable.find(key) != hashTable.end()){

			ListNode *temp = hashTable[key];

			if(tail != head){
				tail -> next = temp;
			}
			if(temp != head){
				temp -> previous ->next = temp ->next;
				temp -> previous = tail;
			} else{
				head = temp ->next;
				temp -> previous = tail;
			}

			temp -> next = nullptr;

			if(head != tail){
				tail = tail -> next;
			}

			return temp->value;

		} else{
			return -1;
		}
    }
    
    void set(int key, int value) {

		ListNode *newNode = new ListNode(key, value);
		hashTable[key] = newNode;

		if(head != nullptr && hashTable.size() < cacheCapacity){
			//General Case
			tail -> next = newNode;
			newNode ->previous = tail;
			tail = tail -> next;
		} else if(hashTable.size() > cacheCapacity){

			if(head != tail){
				ListNode *temp = head->next;
				hashTable.erase(head -> key);
				delete head;
				head = temp;
				tail -> next = newNode;
				newNode ->previous = tail;
				tail = tail -> next;
			} else {
				hashTable.erase(head -> key);
				delete head;
				head = newNode;
				tail = head;
			}

		} else if(head == nullptr){
			head = newNode;
			tail = newNode;
		}
    }
};