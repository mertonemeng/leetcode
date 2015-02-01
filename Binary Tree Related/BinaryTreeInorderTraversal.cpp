#include "stdafx.h"
#include "BinaryTree.cpp"
#include <vector>
#include <stack>

using namespace std;

class BinaryTreeInorderTraversal{
public:
	 vector<int> inorderTraversal(TreeNode *root) {
		stack<TreeNode *> travStack;
		TreeNode *ptr = root;
		vector<int> result;

		if(root == nullptr)return result;

		while (ptr != nullptr)
		{
			while(ptr != nullptr)
			{
				if(ptr ->right != nullptr)travStack.push(ptr->right);
				travStack.push(ptr);
				ptr = ptr->left;
			}
			ptr = travStack.top();
			travStack.pop();

			while((travStack.size() > 0) && (ptr->right == nullptr))
			{
				result.push_back(ptr->val);
				ptr = travStack.top();
				travStack.pop();
			}
			result.push_back(ptr->val);

			if(travStack.size() > 0)
			{
				ptr = travStack.top();
				travStack.pop();
			}
			else ptr = nullptr;
		}

		return result;
    }
};