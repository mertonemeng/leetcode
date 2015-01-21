#include "stdafx.h"
#include "BinaryTree.cpp"
#include <string>
#include <stack>

using namespace std;

class MaximumDepthofBinaryTree {
public:
    static int maxDepth(TreeNode *root) {
        long maxDepthNum = 0;
		long levelCount = 0;
		if (root == nullptr)return maxDepthNum;
		if(root ->left == nullptr && root ->right == nullptr)
		{
			maxDepthNum++;
			return maxDepthNum;
		}
		else
		{
			deepthFisrtSearch(root, levelCount, maxDepthNum);
		}
		return maxDepthNum;
    }
	static void deepthFisrtSearch(TreeNode *root, long int levelCount, long &maxDepthNum)
	{
		levelCount++;
		if(root ->left != nullptr)
		{
			deepthFisrtSearch(root ->left, levelCount, maxDepthNum);
		}
		if(root ->right != nullptr)
		{

			deepthFisrtSearch(root ->right, levelCount, maxDepthNum);
		}
		if(root ->left == nullptr && root ->right == nullptr)
		{
			//To calculate the Min Depth, use the following sentence
			//if(maxDepthNum == 0)maxDepthNum = levelCount;
			//if (levelCount < maxDepthNum)maxDepthNum = levelCount;
			if (levelCount > maxDepthNum)maxDepthNum = levelCount;
		}
	}
};


