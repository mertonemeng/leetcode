#include "stdafx.h"
#include "BinaryTree.cpp"
#include <vector>

using namespace std;

class ConvertSortedArraytoBinarySearchTree {
public:
    static TreeNode *sortedArrayToBST(vector<int> &num) {
		TreeNode *root = nullptr;

		if(num.size() == 0)return nullptr;

		int first = 0, last = num.size() - 1;
		balance(root, num, first, last);

		return root;
    }

	static void balance(TreeNode *&root,vector<int> num, int first, int last)
	{
		if(first <= last)
		{
			int middle = (first + last)/2;
			root = new TreeNode(num[middle]);
			balance(root -> left, num, first, middle - 1);
			balance(root -> right, num, middle + 1, last);
		}
	}
};