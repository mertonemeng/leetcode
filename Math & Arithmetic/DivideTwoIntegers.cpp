#include "stdafx.h"
#include <climits>
#include <algorithm>
class DivideTwoIntegers {
public:
    typedef long long ll;
    int divide(int dividend, int divisor) {
    
        /******* handling the case of overflow *******/
        if(divisor == 1)
            return dividend;
		if(dividend == INT_MIN && abs(divisor) == 1)
			return INT_MAX;
        /*********************************************/
    
        int sign = (dividend > 0 ^ divisor > 0) ? -1 : 1;
    
        ll ans = 0;
        ll end = abs((ll)dividend), sor = abs((ll)divisor);
    
        while(end >= sor) {
            ll temp  = sor;
            ll power = 1;
            while((temp << 1) < end) {
                power <<= 1;
                temp  <<= 1;
            }
            ans += power;
            end -= temp;
        }
        return sign * ans;
    }
};