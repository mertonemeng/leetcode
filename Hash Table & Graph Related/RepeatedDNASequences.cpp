#include "stdafx.h"
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class RepeatedDNASequences {
public:
    static vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		unordered_map<string, int> hashTable;
		int n = s.size();

		if(n == 0){
			return result;
		}

		int pos = 0;

		while(pos < n - 10){
			auto it = hashTable.find(s.substr(pos, 10));
			if(it == hashTable.end()){
				hashTable[s.substr(pos, 10)] = 1;
			} else{
				if(it->second == 1){
					result.push_back(s.substr(pos, 10));
					(it->second) = 2;
				}
			}
			pos++;
		}

		return result;
    }
};