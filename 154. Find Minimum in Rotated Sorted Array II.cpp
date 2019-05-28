//154.Find Minimum in Rotated Sorted Array II
//Hard
//¶þ·Ö·¨

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.size() == 1 || nums.front() < nums.back()) return nums[0];
		int left = 0, right = nums.size() - 1;
		while (left + 1 < right) {
			int mid = left + (right - left) / 2;
			// 1 0 1 1 1,  1 1 1 0 1
			if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
				return helper(nums, left, right);
			}
			else if (nums[mid] >= nums[left]) {
				left = mid;
			}
			else if (nums[mid] < nums[left]) {
				right = mid;
			}
		}
		return min(nums[left], nums[right]);
	}
	int helper(vector<int>& nums, int left, int right) {
		int ret = nums[left];
		for (int i = left + 1; i <= right; ++i) {
			if (nums[i] < ret) ret = nums[i];
		}
		return ret;
	}
};