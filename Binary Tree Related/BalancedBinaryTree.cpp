#include "stdafx.h"
#include "BinaryTree.cpp"
#include <math.h>
class BalancedBinaryTree {
public:
    static bool isBalanced(TreeNode *root) {
		int levelCount = 0;
		bool result = true;

		if (root == nullptr)return true;

		depthFisrtSearch(root, result);

		return result;
    }

	static int depthFisrtSearch(TreeNode *root, bool &result)
	{
		int height = 0, leftHeight = 0, rightHeight = 0;

		if(!result)return 0;

		if(root ->left != nullptr)
		{
			leftHeight = depthFisrtSearch(root ->left, result);
			if(!result)return 0;
		}
		else
		{
		    leftHeight = 0;
		}
		
		if(root ->right != nullptr)
		{
			rightHeight = depthFisrtSearch(root ->right, result);
			if(!result)return 0;
		}
		else
		{
		    rightHeight = 0;
		}
		
		if(root ->left == nullptr && root ->right == nullptr)
		{
			height = 1;
			return height;
		}

		if(abs(leftHeight - rightHeight) > 1)result = false;

		if(leftHeight > rightHeight)height = leftHeight + 1;
		else height = rightHeight + 1;

	}
};