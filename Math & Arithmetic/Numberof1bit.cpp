#include "stdafx.h"
#include <stdint.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        char mask = 0x01;
		int count = 0;

        for(int i = 0; i < 32;i++){
            char temp = n & mask;
			if (temp == 1){
				count++;
			}

			n>>=1;
        }

		return count;
    }
};