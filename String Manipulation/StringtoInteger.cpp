#include "stdafx.h"
#include <string>
#include <math.h>
using namespace std;

class StringtoInteger {
public:
    static int atoi(const char *str) {
        bool isNegative = false;
		int startPos = 0, endPos = 0;
		double result = 0.0;

		for(int i = 0; (str + i) != '\0' ;i++)
		{
			if(*(str + i) != ' ')
			{
				startPos = i;
				break;
			};
		}

		if((*(str + startPos) != '+') && (*(str + startPos) != '-'))
		{
			if(*(str + startPos) < '0' || *(str + startPos)> '9')return 0;
		}
		else
		{
			if(*(str + startPos + 1) < '0' || *(str + startPos + 1)> '9')return 0;
			if(*(str + startPos) == '-')isNegative = true;
			startPos++;
		}

		for(int i = startPos; (str + i) != '\0' ;i++)
		{
			if(*(str + i) < '0' || *(str + i)> '9')
			{
				endPos = i ;
				break;
			}
		}

		for(int i = startPos; i < endPos;i++)
		{
			int digit = (int)(*(str + i) - 48);
			if(isNegative)
			{
				if ((digit * pow(10.0, endPos - i - 1)) >= INT_MAX) return INT_MIN;
				result -= (digit * pow(10.0, endPos - i - 1));
				if (result <= INT_MIN)return INT_MIN;
			}
			else 
			{
				if ((digit * pow(10.0, endPos - i - 1)) >= INT_MAX) return INT_MAX;
				result += (digit * pow(10.0, endPos - i - 1));
				if (result >= INT_MAX)return INT_MAX;
			}
		}

		return (int)result;
    }
};