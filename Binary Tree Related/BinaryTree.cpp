#include "stdafx.h"

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class BinaryTree
{
public:
	static TreeNode* generateBinaryTree()
	{
		TreeNode *root = new TreeNode(1);

		TreeNode *nodeA = new TreeNode(2);
		TreeNode *nodeB = new TreeNode(2);
		TreeNode *nodeC = new TreeNode(6);
		TreeNode *nodeD = new TreeNode(5);
		TreeNode *nodeE = new TreeNode(5);
		TreeNode *nodeF = new TreeNode(6);

		root -> left = nodeA;
		root -> right = nodeB;
		nodeA -> left = nodeC;
		nodeA -> right = nodeD;
		nodeB -> left = nodeE;
		nodeB -> right = nodeF;

		return root;
	}
};