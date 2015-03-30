#include "stdafx.h"
#include <unordered_map>

using namespace std;

class LRUCache {
private:
	struct Node{
        Node *prev;
        Node *next;
        int key;
        int value;

		Node(int key, int value) {
            this->key = key;
            this->value = value;
			prev = NULL;
            next = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> hs;
    Node *head;
    Node *tail;

public:
	LRUCache(int capacity) {
        this->capacity = capacity;
		head = new Node(-1, -1);
		tail = new Node(-1, -1);
        tail->prev = head;
        head->next = tail;
    }

    int get(int key) {
        if( hs.find(key) == hs.end()) {
            return -1;
        }

        // remove current
        Node *current = hs[key];
        current->prev->next = current->next;
        current->next->prev = current->prev;

        // move current to tail
        move_to_tail(current);

        return hs[key]->value;
    }

    void set(int key, int value) {
        if( get(key) != -1) {
            hs[key]->value = value;
            return;
        }

        if (hs.size() == capacity) {
            hs.erase(head->next->key);
            head->next = head->next->next;
            head->next->prev = head;
        }

        Node *insert = new Node(key, value);
        hs[key]= insert;
        move_to_tail(insert);
    }

    void move_to_tail(Node* current) {
        current->prev = tail->prev;
        tail->prev = current;
        current->prev->next = current;
        current->next = tail;
    }
};