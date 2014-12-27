// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ReverseWordsinString.cpp"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string str;

	getline (cin,str);

	ReverseWordsinString::reverseWords(str);

	cout<<str<<endl;
	return 0;
}

