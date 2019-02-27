//647. Palindromic Substrings
//Medium
//DP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
		int n = s.size();
		int ret = n;
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		for (int i = 0; i<n; i++) {
			dp[i][i] = true;
			if (i>0 && s[i] == s[i - 1]) {
				dp[i - 1][i] = true;
				ret++;
			}
		}
		for (int i = n - 3; i >= 0; i--) {
			for (int j = i + 2; j<n; j++) {
				dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
				if (dp[i][j]) {
					ret++;
				}
			}
		}
		return ret;
	}
};