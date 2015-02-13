#include "stdafx.h"

class SearchInRotatedSortedArray {
public:
    static int search(int A[], int n, int target) {
		int start = 0, end = n -1;
		int mid = 0;

		if(n == 0)return -1;

		while(start + 1 < end){
			mid = start + (end - start)/2;
			if(A[start] > A[mid]){
				if(A[mid] <= target && A[end] >= target){
					start = mid;
				}
				else{
					end = mid;
				}
			}
			else{
				if(A[mid] >= target && A[start] <= target){
					end = mid;
				}
				else{
					start = mid;
				}

			}
		}

        if (A[end] == target) {
			return end;
        }
        else if (A[start] == target){
			return start;
        }
		else{
			return - 1;
		}

    }
};