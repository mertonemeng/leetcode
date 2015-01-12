#include "stdafx.h"
#include <math.h>
#include <vector>

using namespace std;

class LengthofLastWord {
public:
    static int lengthOfLastWord(const char *s) {
		int i = 0, count = 0;
		int result = 0;
		while(s[i]!='\0')
		{
			if(s[i]!=' ')
			{
				count++;
			}
			else
			{
				if(count > 0) result = count;
				count = 0;
			}
			i++;
		}
		if(count > 0)return count;
		else return result;
    }
};