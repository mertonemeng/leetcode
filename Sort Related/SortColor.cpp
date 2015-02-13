#include "stdafx.h"

class Solution {
public:
	//Version one: slow one with Counting SOrt
    void sortColors(int A[], int n) {
        int red = 0, white = 0, blue = 0;
		for(int i = 0;i < n; i++)
		{
			switch(A[i])
			{
			case 0: red++;
				break;
			case 1: white++;
				break;
			case 2:
				blue++;
				break;
			default: break;
			}
		}

		for(int i = 0; i < n; i++)
		{
			if(red > 0)
			{
				A[i] = 0;
				red--;
			}
			else if(white > 0)
			{
				A[i] = 1;
				white--;
			}
			else if(blue > 0)
			{
				A[i] = 2;
				blue--;
			}
		}
    }

	//Version two: Quick One

	void sortColors2(int A[], int n) {
        int start = 0, end = n - 1;
		for(int i = 0;i < n; i++)
		{
			if(A[i] == 0)
			{
				A[start] = 1;
				start++;
			}
		}
    }
};