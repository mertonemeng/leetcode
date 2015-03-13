#include "stdafx.h"
#include "BinaryTree.cpp"
#include <vector>

using namespace std;

class Solution {
public:
    static TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

	    if(inorder.size() == 0){
	        return nullptr;
	    }
	        
	    TreeNode* node = createTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
	    return node;
	}
	    
	static TreeNode* createTree(vector<int> &inorder,int inbegin,int inend,vector<int> &postorder,int postbegin,int postend){
	    if(inbegin>inend){
	    	return nullptr;
	    }
	    	
	    int  root=postorder[postend];
	    int index=0;
	    for(int i=inbegin;i<=inend;i++){
	    	if(root==inorder[i]){
	    		index=i;
	    		break;
	    	}
	    }
	    	
	    int len=index-inbegin;
	    TreeNode *left = createTree(inorder, inbegin, index-1, postorder, postbegin, postbegin+len-1);
	    TreeNode *right = createTree(inorder, index+1, inend, postorder, postbegin+len, postend-1);
	    TreeNode *node= new TreeNode(root);
		node->left = left;
	    node->right = right;
	    return node;
	}
};