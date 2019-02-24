//91. Decode Ways
//Medium
//DP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	//dp[i]:以s中第i位结尾的解码种类数
	int numDecodings(string s) {
		if (s[0] == '0') return 0;
		vector<int> dp(s.size() + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= s.size(); i++) {
			int tmp = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
			if (tmp >= 10 && tmp <= 26) dp[i] += dp[i - 2];
			if (s[i - 1] != '0') dp[i] += dp[i - 1];
		}
		return dp[s.size()];
	}
};