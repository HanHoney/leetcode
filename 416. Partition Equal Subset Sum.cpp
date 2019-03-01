//416. Partition Equal Subset Sum
//Medium
//DP

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (int num : nums) {
			sum += num;
		}
		if (sum % 2 == 1) return false;
		sum /= 2;
		vector<bool> dp(sum + 1, false);
		dp[0] = true;
		for (int num : nums) {
			for (int i = sum; i >= num; i--) {
				dp[i] = dp[i] || dp[i - num];
			}
			if (dp[sum]) return true;
		}
		return false;
	}
};
