#include "stdafx.h"
#include <string>
#include <unordered_map>
using namespace std;

class LongestSubstringWithoutRepeatingCharacters {
public:
    static int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> hastTable;
		int maxLen = 0;
		int start = 0, ptr = 0;

		while(ptr < s.size()){
			auto it = hastTable.find(s[ptr]);
			if(it == hastTable.end()){
				hastTable[s[ptr]] = ptr;
			} else{
				while(start < hastTable[s[ptr]] + 1){
					hastTable.erase(s[start]);
					start++;
				}
				hastTable[s[ptr]] = ptr;
			}
			ptr++;
			maxLen = maxLen < (ptr-start) ? (ptr-start):maxLen; 
		}

		return maxLen;
    }
};