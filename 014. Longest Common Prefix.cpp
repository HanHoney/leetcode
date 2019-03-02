//14. Longest Common Prefix
//Easy
//DC

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() <= 0) {
			return "";
		}
		return longestCommonPrefix(strs, 0, strs.size() - 1);
	}
	string longestCommonPrefix(vector<string>& strs, int left, int right) {
		if (left == right) return strs[left];
		int mid = (left + right) / 2;
		string s1 = longestCommonPrefix(strs, left, mid);
		string s2 = longestCommonPrefix(strs, mid + 1, right);
		for (int i = 0; i < min(s1.size(), s2.size()); i++) {
			if (s1[i] != s2[i]) {
				return s1.substr(0, i);
			}
		}
		return s1.size()<s2.size() ? s1 : s2;
	}
};