#include "stdafx.h"
#include <string>

//Can be more concise

using namespace std;

class AddBinary {
public:
    static string addBinary(string a, string b) {
        
		const int asciiOffset = 48;

		string result = a.size()>b.size()?a:b;

		int maxSize = a.size()>b.size()?a.size():b.size();
		bool isCarry = false;
		
		for(int i = 0; i < maxSize; i++)
		{
			if(i < a.size() && i < b.size())
			{
				int digisum = (int) (a.at(a.size()-1-i)) + (int) (b.at(b.size()-1-i)) - 2*asciiOffset;
				if (isCarry)
				{
					digisum += 1;
					isCarry = false;
				}

				switch (digisum)
				{
				case 0:
					result.at(maxSize-1-i) = '0';
					isCarry = false;
					break;
				case 1:
					result.at(maxSize-1-i) = '1';
					isCarry = false;
					break;
				case 2:
					result.at(maxSize-1-i) = '0';
					isCarry = true;
					break;
				case 3:
					result.at(maxSize-1-i) = '1';
					isCarry = true;
					break;
				default:
					break;
				}
			}
			else if (i >= a.size() && i < b.size())
			{
				int digisum = (int) (b.at(b.size()-1-i)) - asciiOffset;
				if (isCarry)
				{
					digisum += 1;
					isCarry = false;
				}
				switch (digisum)
				{
				case 0:
					result.at(maxSize-1-i) = '0';
					isCarry = false;
					break;
				case 1:
					result.at(maxSize-1-i) = '1';
					isCarry = false;
					break;
				case 2:
					result.at(maxSize-1-i) = '0';
					isCarry = true;
					break;
				default:
					break;
				}

			}
			else if (i < a.size() && i >= b.size())
			{
				int digisum = (int) (a.at(a.size()-1-i)) - asciiOffset;
				if (isCarry)
				{
					digisum += 1;
					isCarry = false;
				}
				switch (digisum)
				{
				case 0:
					result.at(maxSize-1-i) = '0';
					isCarry = false;
					break;
				case 1:
					result.at(maxSize-1-i) = '1';
					isCarry = false;
					break;
				case 2:
					result.at(maxSize-1-i) = '0';
					isCarry = true;
					break;
				default:
					break;
				}
			}
		}

		if(isCarry) result = "1" + result;

		return result;
    }

};