#include "stdafx.h"
#include "BinaryTree.cpp"
#include <stack>
#include <vector>

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> travStack;
        vector<int> result;
        TreeNode* p = root, *q = root;
        
		if(root == nullptr)return result;
        
		while(p != nullptr){
			for(;p -> left != 0; p = p -> left)
				travStack.push(p);
			while (p->right == nullptr || p -> right == q){
				result.push_back(p->val);
				q = p;
				if(travStack.empty())
					return result;
				p = travStack.top();
				travStack.pop();
			}
			travStack.push(p);
			p = p->right;
		}

		return result;
    }
};