#include "stdafx.h"
#include "BinaryTree.cpp"
#include <stack>
#include <vector>
using namespace std;

class BinaryTreeZigzagLevelOrderTraversal  {
public:
    static vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> result;

		if(root == nullptr){
			return result;
		}

		deque<TreeNode *> nodeQue;
		nodeQue.push_back(root);
		int levelCount = 0;
		while(nodeQue.size() > 0){
			vector<int> oneLevel;
			
			int queSize = nodeQue.size();
			for(int i = 0; i < queSize; i++){
				TreeNode *node = nodeQue.front();
				if(node ->left != nullptr){
					nodeQue.push_back(node ->left);
				}
				if(node ->right != nullptr){
					nodeQue.push_back(node ->right);
				}
				oneLevel.push_back(node->val);
				nodeQue.pop_front();
			}
			if(levelCount % 2 != 0){
				reverse(oneLevel.begin(), oneLevel.end());
			}
			result.push_back(oneLevel);
			levelCount++;
		}
        
		return result;
    }
};