//89. Gray Code
//Medium

/*
0 1
00 01 11 10
000 001 011 010 110 111 101 100
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ret(1 << n);
		for (int i = 0; i < (1 << n); ++i) {
			ret[i] = i ^ (i >> 1);
		}
		return ret;
	}

	vector<int> grayCode_1(int n) {
		vector<int> ret(1 << n);
		vector<string> strs(1 << n, "");
		helper(strs, n);
		for (int i = 0; i < 1 << n; ++i) {
			ret[i] = toInt(strs[i]);
		}
		return ret;
	}
	void helper(vector<string>& strs, int n) {
		if (n == 0) {
			return;
		}
		helper(strs, n - 1);
		for (int i = 0; i < 1 << (n - 1); ++i) {
			strs[(1 << n) - 1 - i] = "1" + strs[i];
			strs[i] = "0" + strs[i];
		}
	}
	int toInt(string str) {
		int ret = 0;
		for (auto c : str) {
			ret = c - '0' + (ret << 1);
		}
		return ret;
	}
};