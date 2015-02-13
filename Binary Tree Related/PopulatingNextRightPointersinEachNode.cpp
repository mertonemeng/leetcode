#include "stdafx.h"
#include "BinaryTree.cpp"
#include <stack>
#include <vector>
using namespace std;

class PopulatingNextRightPointersinEachNode {
public:
    static void connect(TreeLinkNode *root) {
		if(root == nullptr)return;

		deque<TreeLinkNode *> nodeQue;
		nodeQue.push_back(root);
		
		while(nodeQue.size() > 0){
			TreeLinkNode *ptr = nodeQue.front();
			int size = nodeQue.size();
			for(int i = 0; i < size;i++){
				TreeLinkNode *temp = nodeQue.front();
				if(temp -> left != nullptr){
					nodeQue.push_back(temp -> left);
				}
				if(temp -> right != nullptr){
					nodeQue.push_back(temp -> right);
				}
				nodeQue.pop_front();
				if(i < size - 1){
					ptr->next = nodeQue.front();
					ptr = ptr->next;
				}
			}
		}
    }
};