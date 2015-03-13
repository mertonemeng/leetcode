#include "stdafx.h"
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

class WordLadderII {
public:
    static vector<vector<string>> findLadders(string start, string end,
            unordered_set<string> &dict) {
        vector<vector<string>> ladders;
        unordered_map<string, vector<string>> map;
        unordered_map<string, int> distance;

        dict.insert(start);
        dict.insert(end);
 
        bfs(map, distance, start, end, dict);
        
        vector<string> path;
        
        dfs(ladders, path, end, start, distance, map);

        return ladders;
    }

    static void dfs(vector<vector<string>> &ladders, vector<string> &path, string crt,
            string start, unordered_map<string, int> &distance,
            unordered_map<string, vector<string>> &map) {
        path.push_back(crt);
		if (crt.compare(start) == 0) {
			reverse(path.begin(), path.end());
			ladders.push_back(path);
            reverse(path.begin(), path.end());
        } else {
            for (string next : map[crt]) {
				if ((distance.find(next) != distance.end()) && distance[crt] == distance[next] + 1) { 
                    dfs(ladders, path, next, start, distance, map);
                }
            }           
        }
		path.pop_back();
    }

    static void bfs(unordered_map<string, vector<string>> &map, unordered_map<string, int> &distance,
            string start, string end, unordered_set<string> &dict) {
        deque<string> q;
		q.push_back(start);
        distance[start] = 0;
        for (string s : dict) {
			vector<string> temp;
            map[s] = temp;
        }
        
        while (!q.empty()) {
            string crt = q.front();
			q.pop_front();
            vector<string> nextvector = expand(crt, dict);
            for (string next : nextvector) {
				map[next].push_back(crt);
				if (distance.find(next) == distance.end()) {
                    distance[next] = distance[crt] + 1;
					q.push_back(next);
                }
            }
        }
    }

	//Expanded to graph

    static vector<string> expand(string crt, unordered_set<string> &dict) {
        vector<string> expansion;

        for (int i = 0; i < crt.length(); i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch != crt[i]) {
                    string expanded = crt;
					expanded[i] = ch;
					if (dict.find(expanded) != dict.end()) {
						expansion.push_back(expanded);
                    }
                }
            }
        }

        return expansion;
    }
};