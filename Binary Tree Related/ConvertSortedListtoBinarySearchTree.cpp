#include "stdafx.h"
#include "BinaryTree.cpp"
#include "LinkList.cpp"

using namespace std;

class ConvertSortedListtoBinarySearchTree {
public:
    static TreeNode *sortedListToBST(ListNode *head) {
		TreeNode *root = nullptr;
		if(head == nullptr)return nullptr;
		balance(root, head, nullptr);
		return root;
    }

	static void balance(TreeNode *&root, ListNode *head, ListNode *end)
	{
		if(head == nullptr)return;

		ListNode *midPtr = head, *endPtr = head;

		while(endPtr!= end)
		{
			endPtr = endPtr ->next;
			if(endPtr == end)break;
			endPtr = endPtr ->next;
			midPtr = midPtr ->next;
		}

		if (end != head)
		{
			root = new TreeNode(midPtr ->val);
			balance(root -> left, head, midPtr);
			balance(root -> right, midPtr->next, end);
		}
	}
};