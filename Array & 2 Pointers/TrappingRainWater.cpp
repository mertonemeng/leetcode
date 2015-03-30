#include "stdafx.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        int a=0;
        int b= n-1;
        int maxm = 0;
        int leftmax=0;
        int rightmax=0;

        while(a<=b){
            leftmax = max(leftmax, A[a]);
            rightmax= max(rightmax, A[b]);
            if(leftmax<rightmax){
                maxm += (leftmax-A[a]);       // leftmax is smaller than rightmax, so the (leftmax-A[a]) water can be stored
                a++;
            }
            else{
                maxm += (rightmax-A[b]);
                b--;
            }
        }
        return maxm;
    }
};