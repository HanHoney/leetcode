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
		multiset<int> mset;		//���������ڵ�¥��
		mset.insert(0);			//�����ƽ�ߣ�ʹ��mset��Զ��Ϊ�գ�������rbegin()�Ϸ���
		for (auto e : events) {
			int x = e.first;
			bool entering = e.second > 0;
			int h = abs(e.second);
			if (entering) {
				if (h > *mset.rbegin()) {	//���һ��Ԫ�ض�Ӧ�ĵ������������ֵ
					ret.emplace_back(make_pair(x, h));
				}
				mset.insert(h);
			}
			else {
				//equal_range()����һ��pair<iterator,iterator>��first�ǵ�һ����С��key�ĵ�����λ�ã�second�ǵ�һ������key�ĵ�����λ�á�
				//ֻɾ��һ��ֵΪkey��Ԫ�أ���ɾ�����event��Ӧ�����Ԫ�ء�
				mset.erase(mset.equal_range(h).first);
				if (h > *mset.rbegin()) {
					ret.emplace_back(make_pair(x, *mset.rbegin()));
				}
			}
		}
		return ret;
	}
};