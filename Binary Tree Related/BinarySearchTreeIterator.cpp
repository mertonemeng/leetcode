#include "stdafx.h"
#include "BinaryTree.cpp"
#include <stack>
#include <vector>

using namespace std;

class BSTIterator {
public:
	deque<int> sortedQue;

    BSTIterator(TreeNode *root) {
		if(root == nullptr){
			return;
		}

		DFS(root, sortedQue);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		if(sortedQue.size()>0){
			return true;
		}
		else{
			return false;
		}
    }

    /** @return the next smallest number */
    int next() {
		int result = sortedQue.front();
		sortedQue.pop_front();
		return result;
    }

	void DFS(TreeNode *root, deque<int> &sortedQue){
		if(root->left != nullptr){
			DFS(root -> left, sortedQue);
		}
		sortedQue.push_back(root ->val);
		if(root->right != nullptr){
			DFS(root -> right, sortedQue);
		}
	}
};