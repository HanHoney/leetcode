//621. Task Scheduler
//Medium
//Greedy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int  leastInterval(vector<char>& tasks, int n) {
		int map[26] = { 0 };
		int maxcnt = 0;
		for (char c : tasks) {
			map[c - 'A']++;
			maxcnt = max(maxcnt, map[c - 'A']);
		}
		int ret = (maxcnt - 1)*(n + 1);
		for (int i = 0; i < 26; i++) {
			if (map[i] == maxcnt) {
				ret++;
			}
		}
		ret = max(ret, (int)tasks.size());
		return ret;
	}
};