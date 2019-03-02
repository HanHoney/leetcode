//406. Queue Reconstruction by Height
//Medium

//按照h升序排列，放到还剩余位置中对应的k处，并且把当前k移除。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	}
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		int n = people.size();
		vector<pair<int, int>> ret(n);
		vector<int> index(n);
		for (int i = 0; i < n; i++) {
			index[i] = i;
		}
		sort(people.begin(), people.end(), cmp);
		for (int i = 0; i < n; i++) {
			int j = people[i].second;
			ret[index[j]] = people[i];
			index.erase(index.begin() + j);
		}
		return ret;
	}
};