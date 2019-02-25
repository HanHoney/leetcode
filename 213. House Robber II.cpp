//213. House Robber II
//Medium
//DP
//∏¥”√198

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		int n = nums.size();
		if (n == 1) return nums[0];
		int res1 = robWithoutCircle(nums, 0, n - 1);
		int res2 = robWithoutCircle(nums, 1, n);
		return max(res1, res2);
	}
private:
	int robWithoutCircle(vector<int>& nums, int left, int right) {
		int prev = 0;
		int curr = nums[left];
		for (int i = left + 1; i < right; i++) {
			int next = max(prev + nums[i], curr);
			prev = curr;
			curr = next;
		}
		return curr;
	}
};
