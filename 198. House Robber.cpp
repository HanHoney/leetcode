//198. House Robber
//Easy
//DP
//dp[i]=max(dp[i-1],dp[i-2]+nums[i]);

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		int n = nums.size();
		int prev = 0, ret = nums[0];
		for (int i = 1; i < n; i++) {
			int tmp = max(prev + nums[i], ret);
			prev = ret;
			ret = tmp;
		}
		return ret;
	}
};