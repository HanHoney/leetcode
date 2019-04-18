//343. Integer Break
//Medium

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1, 0);
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j < i; ++j) {
				dp[i] = max(dp[i], max(j, dp[j])*max(i - j, dp[i - j]));
			}
		}
		return dp[n];
	}
};