// 32. Longest Valid Parentheses
// Hard
/***********
① Brute Force (TLE)
	TC:O(n^3)	SC:O(n)
② DP
	TC:O(n)		SC:O(n)		
③ Stack【未完待续】
	TC:O(n)		SC:O(n)
***********/


#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	/*
	//暴力
	bool isValid(string s) {
		stack<char> st;
		for (auto c : s) {
			if (c == '(') st.push(c);
			else if (!st.empty() && st.top() == '(') st.pop();
			else return false;
		}
		return st.empty();
	}
	int longestValidParentheses_1(string s) {
		int ret = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = i + 1; j < s.size(); j += 2) {
				if (isValid(s.substr(i, j - i + 1))) {
					ret = max(ret, j - i + 1);
				}
			}
		}
		return ret;
	}
	*/

	int longestValidParentheses(string s) {
		int ret = 0;
		if (s.empty()) return ret;
		vector<int> dp(s.size(), 0);
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == ')') {
				if (s[i - 1] == '(') {
					dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
				}
				else if (i - dp[i - 1] >= 1 && s[i - dp[i - 1] - 1] == '(') {
					dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
				}
				ret = max(ret, dp[i]);
			}
		}
		return ret;
	}
};

int main() {
	string str;
	while (cin >> str) {
		Solution s;
		cout << s.longestValidParentheses(str) << endl;
	}
	return 0;
}
