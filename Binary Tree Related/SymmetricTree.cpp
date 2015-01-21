#include "stdafx.h"
#include "BinaryTree.cpp"

class SymmetricTree {
public:
   static bool isSymmetric(TreeNode *root) {
		bool result = true;
		if (root == nullptr)return true;
		CompareSubTree(root->left, root->right, result);

		return result;
    }

	static void CompareSubTree(TreeNode *left, TreeNode *right, bool &symmetricFlag)
	{
		if(left == nullptr && right == nullptr)return;
		else if(left != nullptr && right == nullptr)
		{
			symmetricFlag = false;
			return;
		}
		else if(left == nullptr && right != nullptr)
		{
			symmetricFlag = false;
			return;
		}
		else
		{
			if(left -> val != right->val)
			{
				symmetricFlag = false;
				return;
			}
			if(!symmetricFlag)return;
			CompareSubTree(left ->left, right->right, symmetricFlag);
			CompareSubTree(left ->right, right->left, symmetricFlag);
		}
	}
};