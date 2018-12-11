// 33. Search in Rotated Sorted Array
// Medium

#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (target == nums[mid]) return mid;
			if ((nums[left] <= target && nums[mid] > target) || (nums[left] > nums[mid] && (target >= nums[left] || target < nums[mid]))) {
				right = mid - 1;
			}
			else if ((nums[mid] < target && nums[right] >= target) || (nums[mid] > nums[right] && (target > nums[mid] || target <= nums[right]))) {
				left = mid + 1;
			}
			else break;
		}
		return -1;
	}
};