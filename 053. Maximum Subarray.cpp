//53. Maximum Subarray
//Easy
//DP:O(n) 
//DC:O(logn)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	//TC:O(n) SC:O(n)
	int maxSubArray2(vector<int>& nums) {
		if (nums.size() < 1) return 0;
		int n = nums.size();
		vector<int> dp(n, INT_MIN);    //dp[i]代表以元素nums[i]结尾的最大子序列和。
		dp[0] = nums[0];
		int res = nums[0];
		for (int i = 1; i < n; i++) {
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			res = max(res, dp[i]);
		}
		return res;
	}
	
	//TC:O(n) SC:O(1)
	int maxSubArray1(vector<int>& nums) {
		int n = nums.size();
		if (n < 1) return 0;
		int dp = nums[0];
		int res = nums[0];
		for (int i = 1; i < n; i++) {
			dp = max(dp + nums[i], nums[i]);
			res = max(res, dp);
		}
		return res;
	}

	//TC:O(logn) SC:O(1) 
	//Divide and Conquer
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		if (n < 1) return 0;
		return maxSubArrayDC(nums, 0, n - 1);
	}
private:
	int maxSubArrayDC(vector<int>& nums, int l, int r) {   //分治
		if (l == r) return nums[l];
		int m = (l + r) / 2;
		return max(max(maxSubArrayDC(nums, l, m), maxSubArrayDC(nums, m + 1, r)), maxCrossing(nums, l, r, m));
	}
	int maxCrossing(vector<int>& nums, int l, int r, int m) {
		int sum = 0;
		int leftmax = INT_MIN, rightmax = INT_MIN;
		for (int i = m, sum = 0; i >= l; i--) {   //从中间向两侧扩张
			sum += nums[i];
			leftmax = max(leftmax, sum);
		}
		for (int i = m + 1, sum = 0; i <= r; i++) {
			sum += nums[i];
			rightmax = max(rightmax, sum);
		}
		return leftmax + rightmax;
	}
};