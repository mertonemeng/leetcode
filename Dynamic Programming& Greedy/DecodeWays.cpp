#include "stdafx.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class DecodeWays {
public:
    static int numDecodings(string s) {
		int n = s.size();

		if(n == 0){
			return 0;
		}
		if(s[0] == '0'){
			return 0;
		}

        vector<int> dpCache(3,1);

		for(int i = 1; i < n; i++){
			string str = s.substr(i-1, 2);
			stringstream ss;
			int val = 0;
			ss<<str;
			ss>>val;

			if( val == 10 || val == 20 || (str.size() == 2 && val < 10 && val > 0)){
				dpCache[(i + 1)%3] = dpCache[(i - 1)%3];
			}
			else if(val > 10 && val <= 26){
				dpCache[(i + 1)%3] = dpCache[i%3] + dpCache[(i - 1)%3];
			}
			else if(s[i] == '0' && val > 26 || val == 0){
				return 0;
			}
			else{
				dpCache[(i + 1)%3] = dpCache[i%3];
			}
		}

		return dpCache[n%3];
    }
};