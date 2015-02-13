#include "stdafx.h"
#include "BinaryTree.cpp"
#include <stack>

class ValidateBinarySearchTree {
public:
    static bool isValidBST(TreeNode *root) {
        bool result = true;
		stack<int> leftStk, rightStk;
		if (root ==nullptr)return true;
		DFS(root, leftStk, rightStk, result);
		return result;
    }

	static void DFS(TreeNode *root, stack<int> leftStk, stack<int> rightStk, bool &result)
	{
		if(root == nullptr)return;
		if(result == false)return;

		if(leftStk.size()>0)
		{
			if(root->val >= leftStk.top())
			{
				result = false;
				return;
			}
		}
		if(rightStk.size()>0)
		{
			if(root->val <= rightStk.top())
			{
				result = false;
				return;
			}
		}

		if(root->left != nullptr)
		{
			leftStk.push(root->val);
			DFS(root->left, leftStk, rightStk, result);
			leftStk.pop();
		}
		if(root->right != nullptr)
		{
			rightStk.push(root->val);
			DFS(root->right, leftStk, rightStk, result);
			rightStk.pop();
		}
		if(root->right != nullptr && root->left != nullptr)return;

	}
};