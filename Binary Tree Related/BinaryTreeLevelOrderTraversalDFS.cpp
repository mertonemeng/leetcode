#include "stdafx.h"
#include "BinaryTree.cpp"
#include <stack>
#include <vector>

using namespace std;

class BinaryTreeLevelOrderTraversal {
public:
	static vector<vector<int>> levelOrder(TreeNode *root) {
		vector<vector<int>> result;
		int levelCount = 0;

		if(root == nullptr)return result;

		DepthFirstSearch(root, result, levelCount);

		return result;
	}

	static void DepthFirstSearch(TreeNode *root, vector<vector<int>> &resultVec,int levelCount)
	{
		if(levelCount < resultVec.size())
		{
			resultVec[levelCount].push_back(root->val);
		}
		else
		{
			vector<int> temp;
			resultVec.push_back(temp);
			resultVec[levelCount].push_back(root->val);
		}
		levelCount++;
		if(root ->left != nullptr)
		{
			DepthFirstSearch(root ->left, resultVec, levelCount);
		}
		if(root ->right != nullptr)
		{
			DepthFirstSearch(root ->right, resultVec, levelCount);
		}
	}
};

