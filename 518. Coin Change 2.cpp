//518. Coin Change 2
//Medium
//DP

#include <iostream>
#include <vector>
using namespace std;

//dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		for (int coin:coins) {
			for (int i = coin; i <= amount; i++) {
				dp[i] = dp[i] + dp[i - coin];
			}
		}
		return dp[amount];
	}
};

#if 0
int main() {
	vector<int> coins{ 1,2,5 };
	int amount = 5;
	Solution s;
	cout << s.change(amount, coins) << endl;
	system("pause");
	return 0;
}
#endif