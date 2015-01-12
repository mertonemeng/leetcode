#include "stdafx.h"
#include <math.h>
using namespace std;

class PalindromeNumber {
public:
	static bool isPalindrome(int x) {
		if(x<0)return false;
        int temp = x;
		int digitCount = 0;

		do
		{
			temp = temp/10;
			digitCount++;
		}while(temp > 0);

		for(int i = 1; i < digitCount;i++)
		{
			int x1 = x/((int)pow(10.0,digitCount - i))%10;
			int x2 = x%((int)pow(10.0,i))/pow(10.0,i-1);
			if(x1!= x2)return false;

		}

		return true;
    }
};