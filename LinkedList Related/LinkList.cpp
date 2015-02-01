#include "stdafx.h"

using namespace std;

struct ListNode {
	  int val;
	  ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class LinkList
{
public:

	  static void generateLinkList(ListNode **l1, ListNode **l2)
	  {
		  ListNode *nodeAptr = new ListNode(1);
		  ListNode *nodeBptr = new ListNode(3);
		  ListNode *nodeCptr = new ListNode(5);

		  ListNode *nodeDptr = new ListNode(2);
		  ListNode *nodeEptr = new ListNode(4);
		  ListNode *nodeFptr = new ListNode(6);

		  nodeAptr->next = nodeBptr;
		  nodeBptr->next = nodeCptr;

		  nodeDptr->next = nodeEptr;
		  nodeEptr->next = nodeFptr;

		  *l1 = nodeAptr;
		  *l2 = nodeDptr;
	  }
};