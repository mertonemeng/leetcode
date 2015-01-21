#include "stdafx.h"
#include "BinaryTree.cpp"

class SameTree {
public:
    static bool isSameTree(TreeNode *p, TreeNode *q) {
        bool result = true;
		if (p != nullptr && q != nullptr)
		{
			CompareSubTree(p, q, result);
			return result;
		}
		else if (p == nullptr && q == nullptr)return true;
		else return false;
    }

	static void CompareSubTree(TreeNode *p, TreeNode *q, bool &sameFlag)
	{
		if(p == nullptr && q == nullptr)return;
		else if(p != nullptr && q == nullptr)
		{
			sameFlag = false;
			return;
		}
		else if(p == nullptr && q != nullptr)
		{
			sameFlag = false;
			return;
		}
		else
		{
			if(p -> val != q->val)
			{
				sameFlag = false;
				return;
			}
			if(!sameFlag)return;
			CompareSubTree(p ->left, q->left, sameFlag);
			CompareSubTree(p ->right, q->right, sameFlag);
		}
	}
};