//188. Best Time to Buy and Sell Stock IV
//Hard
//DP
//dp[k][i]表示到第i天最多进行k次交易时的最大利润
//dp[k][i] = max(dp[k][i - 1], prices[i] - prices[j] + dp[k - 1][j - 1])  j ∈[0, i - 1]
//dp[0][i] = 0, dp[k][0] = 0.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		if (n < 2) return 0;
		int ret = 0;
		if (k * 2 >= n) {
			int ret = 0;
			for (int i = 1; i < prices.size(); i++) {
				if (prices[i] > prices[i - 1]) {
					ret += prices[i] - prices[i - 1];
				}
			}
			return ret;
		}
		vector<vector<int>> dp(k + 1, vector<int>(n, 0));
		for (int i = 1; i <= k; i++) {
			int tmp = prices[0];
			for (int j = 1; j < n; j++) {
				tmp = min(tmp, prices[j] - dp[i - 1][j - 1]);
				dp[i][j] = max(dp[i][j - 1], prices[j] - tmp);
			}
		}
		return dp[k][n - 1];
	}
};

