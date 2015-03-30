#include "stdafx.h"
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

class MergeIntervals {
public:
    static vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
		vector<Interval> result;
		deque<int> startQue, endQue;

		if(n == 0){
			return result;
		}

		for(int i = 0; i < n; i++){
			startQue.push_back(intervals[i].start);
			endQue.push_back(intervals[i].end);
		}

		sort(startQue.begin(), startQue.end());
		sort(endQue.begin(), endQue.end());

		while(!endQue.empty()){
			int start = startQue.front();
			startQue.pop_front();

			while(!startQue.empty() && (startQue.front() <= endQue.front())){
				startQue.pop_front();
			}

			int end = 0;

			while(startQue.size() < endQue.size()){
				end = endQue.front();

				if(!startQue.empty() && (startQue.front() <= endQue.front())){
					startQue.pop_front();
				}

				endQue.pop_front();
			}

			result.push_back(Interval(start, end));
		}

		return result;
    }

	static vector<Interval> generateInterval(){
		vector<Interval> result;

		result.push_back(Interval(1, 3));
		result.push_back(Interval(2, 6));
		result.push_back(Interval(5, 10));
		result.push_back(Interval(15, 18));

		return result;
	}
};