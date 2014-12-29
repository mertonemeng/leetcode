#include "stdafx.h"
#include <string>
#include <math.h>
using namespace std;

class ExcelSheetColumnNum {
public:
    static int titleToNumber(string s) {
        int asciiOffset = 64;
		int resultNum = 0;
		for(int i = 0; i < s.size(); i++)
		{
			int digiNum = (int) s.at(s.size()-i -1) - asciiOffset;
			resultNum += digiNum * pow(26,i);
		}

		return resultNum;
    }
};