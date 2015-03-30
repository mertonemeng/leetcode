#include "stdafx.h"
#include <unordered_set>

using namespace std;

class FirstMissingPositive {
public:
    static int firstMissingPositive(int A[], int n) {
        unordered_set<int> numSet;

		if(n <= 0){
			return 1;
		}

		for(int i = 0; i < n; i++){
			if(A[i] > 0){
				numSet.insert(A[i]);
			}
		}

		for(int i = 1; i <= numSet.size(); i++){
			if(numSet.find(i) == numSet.end()){
				return i;
			}
		}

		return numSet.size() + 1;
    }
};