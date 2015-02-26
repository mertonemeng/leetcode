#include "stdafx.h"

class Solution {
public:
    static int strStr(char *haystack, char *needle) {
        int needleLen = getLength(needle);
		int haystackLen = getLength(haystack);
		int result = -1;
		bool matchFlag = true;

		if(needleLen > haystackLen)
			return -1;
		if(needleLen == 0 || haystackLen == 0)
			return 0;


		for(int i = 0; i < haystackLen - needleLen + 1; i++){
			int j = 0;
			for(j = 0;j < needleLen; j++){
				if(*(haystack + i + j) != *(needle + j)){
					matchFlag = false;
					break;
				}
			}
			if(matchFlag){
				result = i;
				break;
			}
			matchFlag = true;
		}

		return result;
    }

	static int getLength(char *str){
		int length = 0;

		for(int i = 0;*(str + i) != '\0';i++){
			length++;
		}

		return length;
	}
};