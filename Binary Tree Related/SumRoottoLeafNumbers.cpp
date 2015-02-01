#include "stdafx.h"
#include "BinaryTree.cpp"
#include <string>
#include <sstream>

using namespace std;

class SumRoottoLeafNumbers {
public:
    static int sumNumbers(TreeNode *root) {
        string numStr = "";
		int result = 0;
		
		if (root == nullptr)return result;

		depthFisrtSearch(root, numStr, result);

		return result;
    }

	static void depthFisrtSearch(TreeNode *root, string numStr, int &result)
	{
		numStr = numStr + (char)(root->val + 48);
		if(root ->left != nullptr)
		{
			depthFisrtSearch(root ->left, numStr, result);
		}
		if(root ->right != nullptr)
		{
			depthFisrtSearch(root ->right, numStr, result);
		}
		if(root ->left == nullptr && root ->right == nullptr)
		{
			stringstream ss;
			int temp;
			ss<<numStr;
			ss>>temp;
			result += temp;
		}
	}
};