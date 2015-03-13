#include "stdafx.h"
#include <string>

using namespace std;

class LongestPalindromicSubstring {
public:
    static string longestPalindrome(string s) {
    int i = 0;
    int l = 0;
    int n = s.size();

    for(int j = 0;j<n;j++){
		if(isPalindrome(s.substr( j-l, l))){
            i = j-l;
            l = l+1;
        }else if(j-l-1>=0 && isPalindrome(s.substr( j-l, l))){
            i = j-l-1;
            l = l+2;
        }
    }

    return s.substr(i, l);
    }

	 static bool isPalindrome(string s) {

        int n = s.size();

        // Strip the string (reusing storage)
        int pos = 0; 
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (isalnum(c)) {
                s[pos++] = tolower(c);
            }
        }

        if (pos <= 1) return true; // p holds actual length now

        int x = 0;
        pos--;

        while (x < pos) { // Standard 2 pointers go like --> <-- check
            if (s[x] != s[pos])
                return false;
            x++;
            pos--;
        }

        return true;
    }
};