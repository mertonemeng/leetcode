#include "stdafx.h"
#include "Graph.cpp"
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

class CloneGraph {
public:
    static UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

		if(node == nullptr)
			return nullptr;

		deque<UndirectedGraphNode *> nodeQue;
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hashTable;

		nodeQue.push_back(node);

		while(!nodeQue.empty()){
			UndirectedGraphNode *curNode = nodeQue.front();
			auto it = hashTable.find(curNode);

			if(it != hashTable.end()){
				nodeQue.pop_front();
			} else{
				hashTable[curNode] = new UndirectedGraphNode(curNode ->label);
				for(int i = 0; i < (curNode->neighbors).size();i++){
					nodeQue.push_back((curNode->neighbors)[i]);
				}
				nodeQue.pop_front();
			}
		}

		auto it = hashTable.begin();

		while(it != hashTable.end()){
			UndirectedGraphNode *curNode = it->first;

			UndirectedGraphNode *cloneNode = it->second;

			for(int i = 0; i < (curNode->neighbors).size();i++){
				(cloneNode->neighbors).push_back(hashTable[(curNode->neighbors)[i]]);
			}
			
			it++;
		}

		UndirectedGraphNode *cloneSource = hashTable[node];

		return cloneSource;
    }
};