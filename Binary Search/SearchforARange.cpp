#include "stdafx.h"
#include <vector>

using namespace std;

class SearchforARange {
public:
    static vector<int> searchRange(int A[], int n, int target) {
        int start = 0, end = n - 1;
		int mid = 0;
		vector<int> index;

		if(n == 0)return index;

		while(start + 1 < end)
		{
			mid = start + (end - start)/2;
			if(A[mid] == target)end = mid;
			else if(A[mid] > target)end = mid;
			else if(A[mid] < target)start = mid;
		}

		if (A[start] == target) 
		{
			index.push_back(start);
        }
        else if (A[end] == target) 
		{
			index.push_back(end);
        }
		else
		{
			index.push_back(-1);
		}

		start = 0;
		end = n - 1;

		while(start + 1 < end)
		{
			mid = start + (end - start)/2;
			if(A[mid] == target)start = mid;
			else if(A[mid] > target)end = mid;
			else if(A[mid] < target)start = mid;
		}

		if (A[end] == target) 
		{
			index.push_back(end);
        }
        else if (A[start] == target) 
		{
			index.push_back(start);
        }
		else
		{
			index.push_back(-1);
		}

		return index;
    }
};