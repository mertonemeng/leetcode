#include "stdafx.h"

class RotateArray {
public:
    void rotate(int nums[], int n, int k) {
        for (; k %= n; n -= k)
            for (int i = 0; i < k; i++)
                swap(*nums++, nums[n - k]);
    }
};