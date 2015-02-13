#include "stdafx.h"
#include <unordered_map>

using namespace std;

class SingleNumber {
public:
    static int singleNumber(int A[], int n) 
    {
		unordered_map<int, int> doubleMAP;
		
    	for(int i = 0; i < n; i++ )
    	{
			auto it = doubleMAP.find(A[i]);
			if(it == doubleMAP.end())
			{
				doubleMAP[A[i]] = 1;
			}
			else
			{
				doubleMAP.erase(A[i]);
			}
	    }

		auto it = doubleMAP.begin();

		return it->first;
    }
};