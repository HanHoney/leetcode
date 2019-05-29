//541. Reverse String II
//Easy

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += 2 * k) {
			reverse(s, i, i + k - 1);
		}
		return s;
	}
	void reverse(string& s, int left, int right) {
		right = min(right, (int)s.size() - 1);
		while (left < right) {
			swap(s[left++], s[right--]);
		}
	}
};
