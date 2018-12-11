// 35. Search Insert Position
// Easy

#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty()) return 0;
		int l = 0, r = nums.size() - 1;
		int m;
		while (l <= r) {
			m = (l + r) / 2;
			if (nums[m] == target) return m;
			else if (nums[m] < target) l = m + 1;
			else if (nums[m] > target) r = m - 1;
		}
		return l;
	}
};