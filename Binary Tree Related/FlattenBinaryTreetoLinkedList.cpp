#include "stdafx.h"
#include "BinaryTree.cpp"

class FlattenBinaryTreetoLinkedList {
public:
    static void flatten(TreeNode *root) {
		TreeNode *lastPtr = nullptr;
		if(root == nullptr)return;

		DFS(root, lastPtr);
    }

	static void DFS(TreeNode *root, TreeNode *&lastPtr){
		TreeNode *leftLast = nullptr, *rightLast = nullptr;

		if((root -> left == nullptr) && (root -> right == nullptr)){
			lastPtr = root;
			return;
		}

		if(root -> left != nullptr){
			DFS(root -> left, leftLast);
		}

		if(root -> right != nullptr){
			DFS(root -> right, rightLast);
		}

		TreeNode *temp = root->right;
		if(root->left != nullptr)root -> right = root->left;
		root -> left = nullptr;
		if(leftLast != nullptr)leftLast -> right = temp;
		if(rightLast != nullptr)lastPtr = rightLast;
		else lastPtr = leftLast;
	}
};