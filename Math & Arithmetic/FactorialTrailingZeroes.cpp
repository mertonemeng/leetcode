#include "stdafx.h"
#include <math.h>
#include <vector>
using namespace std;

class FactorialTrailingZeroes {
public:
    static int trailingZeroes(int n) {
        int max = 0;
		int result = 0;

		while(pow(5,max)<=n)
		{
			max++;
		}

		for(int i = 1; i < max; i++)
		{
			result += (n/((int)pow(5,i)));
		}

		return result;
    }
};