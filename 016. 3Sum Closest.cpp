//16. 3Sum Closest

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int ret;
		int dis = INT_MAX;
		for (int i = 0; i < n - 2; ++i) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int j = i + 1;
			int k = n - 1;
			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				if (sum == target) {
					return target;
				}
				if (abs(sum - target) < dis) {
					dis = abs(sum - target);
					ret = sum;
				}
				if (sum < target) {
					++j;
					while (j < k&&nums[j] == nums[j - 1]) {
						++j;
					}
				}
				else {
					--k;
					while (j < k&&nums[k] == nums[k + 1]) {
						--k;
					}
				}
			}
		}
		return ret;
	}

};