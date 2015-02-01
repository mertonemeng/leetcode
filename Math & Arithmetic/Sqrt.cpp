#include "stdafx.h"

using namespace std;

class Sqrt {
public:
    static int sqrt(int x) {
        int start = 0;
		int end = x;
		int result = 0;
		if (x == 0)return 0;
		if (x == 1)return 1;
		BinarySearch(x, start, end, result);

		return result;
    }
	static void BinarySearch(int x, int start, int end, int &result)
	{
		
		int temp = (end - start)/2;
		if(temp == 0)
		{
			result = start;
			return;
		}
		if((start+temp) == (x/(start+temp)))
		{
			result =  start+temp;
		}
		else if((start+temp) > (x/(start+temp)))
		{
			end = start + temp;
			BinarySearch(x, start, end, result);
		}
		else
		{
			start = start + temp;
			BinarySearch(x, start, end, result);
		}
	}
};