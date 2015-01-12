#include "stdafx.h"
#include <string>
#include <stack>
using namespace std;

class RomanToInt {
public:
    static int romanToInt(string s) {
        stack<string> addedNum;
		string alphabetTable[] = {"I","V","X","L","C","D","M","IV","IX","XL","IL","XC","CD","CM"};
		int alphabetNum[] = {1,5,10,50,100,500,1000,4,9,40,49,90,400,900};
		const int originPos = 0;
		int result = 0;

		while(s.size() > 0)
		{
			if(originPos != (s.size()-1))
			{
				switch((char)(s.at(originPos)))
				{
				case 'I':
					if((s.at(originPos+1) == 'V') || (s.at(originPos+1) == 'X') || (s.at(originPos+1) == 'L'))
					{
						addedNum.push(s.substr(originPos, 2));
						s = s.substr(originPos+2, (s.size()-1));
					}
					else
					{
						addedNum.push(s.substr(originPos, 1));
						s = s.substr(originPos+1, (s.size()-1));
					}
					break;
				case 'X':
					if((s.at(originPos+1)== 'L') || (s.at(originPos+1) == 'C'))
					{
						addedNum.push(s.substr(originPos, 2));
						s = s.substr(originPos+2, (s.size()-1));
					}
					else
					{
						addedNum.push(s.substr(originPos, 1));
						s = s.substr(originPos+1, (s.size()-1));
					}
					break;
				case 'C':
					if((char)(s.at(originPos+1)) == 'M' || (s.at(originPos+1) == 'D'))
					{
						addedNum.push(s.substr(originPos, 2));
						s = s.substr(originPos+2, (s.size()-1));
					}
					else
					{
						addedNum.push(s.substr(originPos, 1));
						s = s.substr(originPos+1, (s.size()-1));
					}
					break;
				default:
					addedNum.push(s.substr(originPos, 1));
					s = s.substr(originPos+1, (s.size()-1));
					break;
				}
			}
			else
			{
				addedNum.push(s.substr(originPos, 1));
				s = "";
			}
		}

		while(addedNum.size()>0)
		{
			for(int i = 0; i < 14; i++)
			{
				if((addedNum.top().compare(alphabetTable[i])) == 0)
				{
					result += alphabetNum[i];
					addedNum.pop();
				}
				if (addedNum.size() == 0)break;
			}
		}

		return result;
    }
};