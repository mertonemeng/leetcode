#include "stdafx.h"
#include "BinaryTree.cpp"
#include <vector>

using namespace std;

class PathSumII {
public:
    static vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
		vector<int> pathVec;
		int pathSum = 0;

		if(root == nullptr)return result;

		depthFisrtSearch(root, result, pathVec, pathSum, sum);

		return result;

    }

	static void depthFisrtSearch(TreeNode *root, vector<vector<int>> &result, vector<int> pathVec, int pathSum, int sum)
	{
		pathSum += root->val;
		pathVec.push_back(root -> val);
		if(root ->left != nullptr)
		{
			depthFisrtSearch(root ->left, result, pathVec, pathSum, sum);
		}
		if(root ->right != nullptr)
		{
			depthFisrtSearch(root ->right, result, pathVec,pathSum, sum);
		}
		if(root ->left == nullptr && root ->right == nullptr)
		{
			if(pathSum == sum)
			{
				result.push_back(pathVec);
			}
		}
	}
};