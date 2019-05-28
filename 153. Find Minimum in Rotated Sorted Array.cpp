//153. Find Minimum in Rotated Sorted Array
//Medium
//¶þ·Ö·¨

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.front() <= nums.back()) return nums.front();
		int left = 0, right = nums.size() - 1;
		while (left + 1 < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] > nums[left]) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		return min(nums[left], nums[right]);
	}
};