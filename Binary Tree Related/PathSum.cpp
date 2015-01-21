#include "stdafx.h"
#include "BinaryTree.cpp"
#include <string>
#include <stack>

class PathSum {
public:
    static bool hasPathSum(TreeNode *root, int sum) {
        int pathSum = 0;
		bool result = false;
		if (root == nullptr)return false;
		deepthFisrtSearch(root, pathSum, sum, result);

		return result;
    }
	static void deepthFisrtSearch(TreeNode *root, int pathSum, int sum, bool &hasFlag)
	{
		pathSum += root->val;
		if(root ->left != nullptr)
		{
			deepthFisrtSearch(root ->left, pathSum, sum, hasFlag);
		}
		if(root ->right != nullptr)
		{
			deepthFisrtSearch(root ->right, pathSum, sum, hasFlag);
		}
		if(root ->left == nullptr && root ->right == nullptr)
		{
			if (pathSum == sum)hasFlag = true;
		}
	}
};