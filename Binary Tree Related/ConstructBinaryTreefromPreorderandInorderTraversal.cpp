#include "stdafx.h"
#include "BinaryTree.cpp"
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

	    if(inorder.size() == 0){
	        return nullptr;
	    }
	        
	    TreeNode* node = createTree(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1);
	    return node;
	}
	    
	static TreeNode* createTree(vector<int> &inorder,int inbegin,int inend,vector<int> &preorder,int prebegin,int preend){
	    if(inbegin>inend){
	    	return nullptr;
	    }
	    	
	    int  root = preorder[prebegin];
	    int index=0;
	    for(int i=inbegin;i<=inend;i++){
	    	if(root == inorder[i]){
	    		index=i;
	    		break;
	    	}
	    }
	    	
	    int len=index-inbegin;
	    TreeNode *left = createTree(inorder, inbegin, index-1, preorder, prebegin + 1, prebegin+len);
	    TreeNode *right = createTree(inorder, index+1, inend, preorder, prebegin+len + 1, preend);
	    TreeNode *node= new TreeNode(root);
		node->left = left;
	    node->right = right;
	    return node;
    }
};