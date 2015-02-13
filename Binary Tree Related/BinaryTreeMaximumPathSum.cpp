#include "stdafx.h"
#include "BinaryTree.cpp"
#include <climits>

class BinaryTreeMaximumPathSum {
public:
    static int maxPathSum(TreeNode *root) {
		int MaxPath = INT_MIN;
		if(root == nullptr){
			return 0;
		}
        DFS(root, MaxPath);
		return MaxPath;
    }

	static int DFS(TreeNode *root, int &MaxPath){
		int leftPath = 0, rightPath = 0;

		if(root->left != nullptr){
			leftPath = DFS(root->left, MaxPath);
		}

		if(root->right != nullptr){
			rightPath = DFS(root->right, MaxPath);
		}

		MaxPath = MaxPath > (leftPath + rightPath + root->val)? MaxPath : (leftPath + rightPath + root->val);
		MaxPath = MaxPath > (leftPath + root->val)? MaxPath : (leftPath + root->val);
		MaxPath = MaxPath > (rightPath + root->val)? MaxPath : (rightPath + root->val);
		MaxPath = MaxPath > root->val? MaxPath : root->val;

		if(rightPath >= 0 || leftPath >=0){
			return rightPath > leftPath ? (rightPath + root->val):(leftPath + root->val);
		}
		else{
			return root->val;
		}
	}
};