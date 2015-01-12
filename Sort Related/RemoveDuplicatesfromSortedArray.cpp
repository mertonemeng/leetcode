#include "stdafx.h"
#include <vector>
using namespace std;

class RemoveDuplicatesfromSortedArray {
public:
   static int removeDuplicates(int A[], int n) {

	   if(n == 0)return 0;
	   if(n == 1)return 1;
        int count = 0;
        int lastElem = A[0];
        for (int i = 1; i < n; i++){
            if (A[i] != lastElem) 
            {
                count++;
                lastElem = A[i];
            }
			A[count] = A[i];
        }
        return count + 1;
    }
};