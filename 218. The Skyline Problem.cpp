//218. The Skyline Problem
//Hard
//TC:O(NlogN)	SC:O(N)

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
	static bool cmp(pair<int, int> &a, pair<int, int> &b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	}
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> events;
		for (auto building : buildings) {
			events.emplace_back(make_pair(building[0], building[2]));
			events.emplace_back(make_pair(building[1], -building[2]));
		}
		sort(events.begin(), events.end(), cmp);
		vector<pair<int, int>> ret;
		multiset<int> mset;		//还在视线内的楼高
		mset.insert(0);			//加入地平线，使得mset永远不为空，迭代器rbegin()合法。
		for (auto e : events) {
			int x = e.first;
			bool entering = e.second > 0;
			int h = abs(e.second);
			if (entering) {
				if (h > *mset.rbegin()) {	//最后一个元素对应的迭代器，即最大值
					ret.emplace_back(make_pair(x, h));
				}
				mset.insert(h);
			}
			else {
				//equal_range()返回一个pair<iterator,iterator>，first是第一个不小于key的迭代器位置，second是第一个大于key的迭代器位置。
				//只删除一个值为key的元素，即删除这个event对应的入口元素。
				mset.erase(mset.equal_range(h).first);
				if (h > *mset.rbegin()) {
					ret.emplace_back(make_pair(x, *mset.rbegin()));
				}
			}
		}
		return ret;
	}
};