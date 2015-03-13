#include "stdafx.h"
#include <unordered_set>
#include <deque>
#include <string>

using namespace std;

class WordLadder {
public:
	//version 1: TLE

    static int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> searchedDict;
		deque<string> strQue;
		int length = 1;
		strQue.push_back(start);
		auto it = dict.begin();

		while(!strQue.empty()){
			int size = strQue.size();

			for(int i = 0;i < size;i++){
				auto curStr = strQue.front();
				if(countStrDistance(curStr, end) == 1){
					length++;
					return length;
				}
				strQue.pop_front();
				it = dict.begin();
				while(it != dict.end()){
					int distance = countStrDistance(curStr, *it);
					if(distance == 1){
						strQue.push_back(*it);
						it = dict.erase(it);
					}
					else{
						it++;
					}
				}
			}
			length++;
		}

		return 0;
    }

	static int countStrDistance(string str1, string str2){
		
		int distance = 0;

		for(int i = 0; i < str1.size(); i++){
			if(str1[i] != str2[i]){
				distance++;
			}
		}

		return distance;
	}

	//version 2

	static int ladderLength2(string start, string end, unordered_set<string> &dict) {
		if (start == "" || dict.size() == 0) {
            return 0;
        }

        deque<string> queue;
        queue.push_back(start);
        dict.erase(start);
        int length = 1;

        while(!queue.empty()) {
            int count = queue.size();
            for (int i = 0; i<count; i++){
                string current = queue.front();
				queue.pop_front();
                for (char c = 'a'; c <= 'z'; c++) {
                    for (int j=0; j < current.length(); j++) {
                        if (c == current[j]) {
                            continue;
                        }
                        string tmp = current;
						tmp[j] = c;
                        if (tmp.compare(end) == 0) {
                            return length + 1;
                        }
						auto it = dict.find(tmp);
                        if (it != dict.end()){
							queue.push_back(tmp);
                            dict.erase(tmp);
                        }
                    }
                }
            }
            length++;
        }
        return 0;
	}
};