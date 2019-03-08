//395. Longest Substring with At Least K Repeating Characters
//Medium
//DC
//TC:O(nlogn)
//find_first_of 不平衡的分治。应该随机选择。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestSubstring(string s, int k) {
		if (k <= 1) return s.size();
		if (s.size() < k) return 0;
		vector<int> cnt(26, 0);
		for (char c : s) {
			cnt[c - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (cnt[i] > 0 && cnt[i] < k) {
				int idx = s.find_first_of(i + 'a');
				return max(longestSubstring(s.substr(0, idx), k), longestSubstring(s.substr(idx + 1, s.size() - idx - 1), k));
			}
		}
		return s.size();
	}
};
