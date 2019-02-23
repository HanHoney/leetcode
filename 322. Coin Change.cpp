//322. Coin Change
//Medium
//DP
//达到指定数额的【最少使用硬币数】
//另一题目：达到指定数额的方案总数

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount < 1) return 0;
		vector<int> dp(amount + 1, amount + 1);  
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) {
			for (int j = 0; j < coins.size(); j++) {
				if (i >= coins[j]) {
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				}
			}
		}
		if (dp[amount] == amount + 1) return -1;
		return dp[amount];
	}
};

#if 0
int main() {
	vector<int> coins{ 2,5 };
	int amount = 3;
	Solution s;
	cout << s.coinChange(coins, amount) << endl;
	system("pause");
	return 0;
}
#endif