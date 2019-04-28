//268. Missing Number
//Easy

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
#if 0
	int missingNumber(vector<int>& nums) {
		for (int i = 0; i<nums.size();) {
			if (nums[i]<nums.size() && i != nums[i]) {
				swap(nums[i], nums[nums[i]]);
			}
			else {
				i++;
			}
		}
		for (int i = 0; i<nums.size(); i++) {
			if (nums[i] != i) {
				return i;
			}
		}
		return nums.size();
	}
#endif

	int missingNumber(vector<int>& nums) {
		if (nums.empty()) return 0;
		int n = nums.size();
		nums.emplace_back(-1);
		int ret = n;
		for (int i = 0; i < n; ++i) {
			while (nums[i] != i && nums[i] != -1) {
				swap(nums[i], nums[nums[i]]);
			}
			if (nums[i] == -1) {
				ret = i;
			}
		}
		return ret;
	}
};