#include "stdafx.h"
#include <math.h>
class PowFunction {
public:
    static double pow(double x, int n) {
        double result = 0;
		long long count = 1;
		double lastResult = 0;
		double nLong = n;

		if(nLong == 0)return 1;
		else if(nLong < 0)
		{
			x = 1/x;
			nLong = abs(nLong);
		}

		result = x;

		while(nLong>count)
		{
			lastResult = result;
			result *=result;
			count +=count;
		}

		if(count == nLong)return result;
		return lastResult*pow(x, nLong - count/2);
    }
};