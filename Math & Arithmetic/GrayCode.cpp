#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class GrayCode {
public:
	 static vector<int> grayCode(int n) {

		 vector<int> result;

		 if(n == 0){
			 return result;
		 }

        int maxNum = pow(2,n) - 1;
		unordered_set<int> numSet;
		
		for(int i = 0; i <= maxNum; i++){
			numSet.insert(i);
		}

		searchHelper(result, numSet, maxNum);

		return result;
    }

	 static void searchHelper(vector<int> &result, unordered_set<int> &numSet, int &maxNum){

		 if(result.size() == maxNum + 1){
			 return;
		 }

		 auto it = numSet.begin();

		 while(it != numSet.end()){
			if(result.empty() || isOneBitDiff(result.back(), *it)){
				result.push_back(*it);
				it = numSet.erase(it);
				searchHelper(result, numSet, maxNum);

				if(result.size() == maxNum + 1){
					return;
				}

				numSet.insert(result.back());
				result.pop_back();
			}
			else{
				it++;
			}
		 }
	 }

	 static bool isOneBitDiff(int a, int b){
		 int temp = a ^ b;
		 int count = 0;

		 for(int i = 0; i < 32; i++){
			 if(temp & 0x01 == 1){
				 count++;
			 }

			 temp = temp >> 1;

			 if(count > 1){
				 return false;
			 }
		 }

		 return true;
	 }
};