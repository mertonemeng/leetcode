#include "stdafx.h"
#include <stdint.h>

class ReverseBits {
public:
   static uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

		for(int i = 0; i < 32; i++){
			int bit = n%2; 
			n >>= 1;
			result += bit;
			if(i < 31){
				result <<= 1;
			}
		}

		return result;
    }
};