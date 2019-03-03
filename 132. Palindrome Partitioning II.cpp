//132. Palindrome Partitioning II
//Hard
//DP
//pal[i][j]:s[i..j]是否是palindrome dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j]
//dp[i]:s[0..i]至少切几次 dp[i] = 0 when pal[0][i] == true, dp[i] = min{ dp[j - 1] + 1 when pal[j][i] == true } j >= 1 && j <= i

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		int n = s.size();
		if (n < 2) return 0;
		vector<int> dp(n, n);
		vector<vector<bool>> pal(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++) {
			pal[i][i] = true;
			if (i < n - 1 && s[i] == s[i + 1]) {
				pal[i][i + 1] = true;
			}
		}
		for (int i = n - 3; i >= 0; i--) {
			for (int j = i + 2; j < n; j++) {
				pal[i][j] = pal[i + 1][j - 1] && s[i] == s[j];
			}
		}
		for (int i = 0; i < n; i++) {
			if (pal[0][i]) {
				dp[i] = 0;
				continue;
			}
			for (int j = 1; j <= i; j++) {
				if (pal[j][i]) {
					dp[i] = min(dp[i], dp[j - 1] + 1);
				}
			}
		}
		return dp[n - 1];
	}
};
