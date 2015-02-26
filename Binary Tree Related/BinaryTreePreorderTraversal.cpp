#include "stdafx.h"
#include "BinaryTree.cpp"
#include <vector>

using namespace std;

class BinaryTreePreorderTraversal {
public:
    static vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;

		if(root == nullptr)return result;

        DFS(root, result);

		return result;
    }
	static void DFS(TreeNode *root, vector<int> &result)
	{
		result.push_back(root->val);
		if(root -> left != nullptr)
		{
			DFS(root-> left, result);
		}
		if(root ->right != nullptr)
		{
			DFS(root -> right , result);
		}
	}
};