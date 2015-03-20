#include "stdafx.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class RestoreIPAddresses {
public:
    static vector<string> restoreIpAddresses(string s) {
		int level = 0;
		string currentIp = "";
		vector<string> result;

		searchHelper(s, level, currentIp, result);

		return result;
    }

	static void searchHelper(string s, int level, string currentIp, vector<string> &result){

		if(s.size() > 3 && level == 3){
			return;
		}
		if(s.size() > 0 && level > 3){
			return;
		}
		if(s.size() == 0 && level < 3){
			return;
		}
		if(s.size() == 0 && level > 3){
			result.push_back(currentIp.substr(0, currentIp.size()-1));
			return;
		}

		for(int i = 1; i <= 3; i++){
			string temp = currentIp;
			stringstream ss;
			if(i > s.size()){
				return;
			}
			string str = s.substr(0,i);
			int val;
			ss << str;
			ss >> val;

			if(val > 255){
				return;
			}
			if(to_string(val).size() < str.size()){
				continue;
			}
			temp = currentIp + str + ".";

			searchHelper(s.substr(i), level + 1, temp, result);
		}
	}
};