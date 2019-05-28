//64. Minimum Path Sum
//Medium
//TC:O(mn)  SC:O(n)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	// SC:O(n)
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size(), n = grid[0].size();
		vector<int> dp(n);
		dp[0] = grid[0][0];
		for (int i = 1; i < n; ++i) {
			dp[i] = dp[i - 1] + grid[0][i];
		}
		for (int i = 1; i < m; ++i) {
			dp[0] += grid[i][0];
			for (int j = 1; j < n; ++j) {
				dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
			}
		}
		return dp[n - 1];
	}

	//SC:O(mn)
	int minPathSum_1(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < n; i++) {
			dp[0][i] = dp[0][i - 1] + grid[0][i];
		}
		for (int i = 1; i < m; i++) {
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}
		return dp[m - 1][n - 1];
	}
};