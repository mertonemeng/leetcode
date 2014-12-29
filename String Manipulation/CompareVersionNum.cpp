#include "stdafx.h"
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class CompareVersionNum {
public:
	static int compareVersion(string version1, string version2) {

		deque<int> version1Que, version2Que;
		
		CompareVersionNum::getVersionQue(version1Que, version1);
		CompareVersionNum::getVersionQue(version2Que, version2);

		while(version1Que.size()!=0 && version2Que.size()!=0)
		{
			if(version1Que.front() > version2Que.front())
			{
				return 1;
			}
			else if (version1Que.front() < version2Que.front())
			{
				return -1;
			}
			else
			{
				version1Que.pop_front();
				version2Que.pop_front();
			}
		}

		if(version1Que.size() > version2Que.size())
		{
			if(version1Que.front() == 0)return 0;
			else return 1;
		}
		else if(version1Que.size() < version2Que.size())
		{
			if(version2Que.front() == 0)return 0;
			return -1;
		}
		else return 0;
		
	}

	static void getVersionQue(deque<int> &versionQue, string version)
	{
		int dotPos = -1;

		do
		{
			int tempPos = dotPos + 1;
			dotPos = version.find('.',dotPos+1);
			string tempStr = "";
			tempStr.assign(version, tempPos, (dotPos-tempPos));
			stringstream ss(tempStr);
			int versionNum = 0;
			ss >> versionNum;
			versionQue.push_back(versionNum);
		}
		while(version.find('.',dotPos)!= string::npos);
	}
};