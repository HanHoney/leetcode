//56. Merge Intervals
//Medium
//按照start做sort即可

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() :start(0), end(0) {}
	Interval(int s, int e) :start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ret;
		if (intervals.empty()) return ret;
		sort(intervals.begin(), intervals.end(), cmp);
		for (const auto &interval:intervals) {
			if (ret.empty() || interval.start > ret.back().end) {
				ret.push_back(interval);
			}
			else {
				ret.back().end = max(interval.end, ret.back().end);
			}
		}
		return ret;
	}
	static bool cmp(const Interval& a, const Interval& b) {   //注意static
		return a.start < b.start;
	}
};

/*
int main() {
	return 0;
	system("pause");
}
*/