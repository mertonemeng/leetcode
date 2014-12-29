#include "stdafx.h"
#include <string>
#include <math.h>
using namespace std;

class ExcelSheetColumnTitle {
public:
    static string convertToTitle(int n){
        
		string result = "";
		int asciiOffset = 65;
		int resultNum = 0;
		int temp = n;
		int i = 0;

		while(temp > 0)
		{
			int digiNum = (temp - 1)%26;
			temp = (temp - 1)/26;

			char digiChar = (char) (digiNum + asciiOffset);
			result = digiChar + result;

		}

		return result;
    }
};