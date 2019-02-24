//279. Perfect Squares
//Medium
//DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int numSquares(int n) {
		if (n < 1) return 0;
		vector<int> dp(n + 1, n);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j*j <= i; j++) {
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
		}
		return dp[n];
	}
};

#if 0
int main() {
	int n;
	Solution s;
	while (cin >> n) {
		cout << s.numSquares(n) << endl;
	}
	return 0;
}
#endif