//152. Maximum Product Subarray
//Medium
//dp
//有正有负，同时记录dpMax和dpMin

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	//TC:O(n)	SC:O(1)
	int maxProduct(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];
		int ret = nums[0];
		int dpMax = nums[0], dpMin = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < 0) swap(dpMax, dpMin);
			dpMax = max(nums[i], nums[i] * dpMax);
			dpMin = min(nums[i], nums[i] * dpMin);
			ret = max(ret, dpMax);
		}
		return ret;
	}

	//TC:O(n)	SC:O(n)
	int maxProduct1(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];
		int ret = nums[0];
		vector<int> dpMax = nums;
		vector<int> dpMin = nums;
		for (int i = 1; i < nums.size(); i++) {
			dpMax[i] = max(max(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]), nums[i]);
			dpMin[i] = min(min(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]), nums[i]);
			ret = max(ret, dpMax[i]);
		}
		return ret;
	}
};

//
//int main() {
//	vector<int> nums{ 0,-1,-4,1,-3,-2 };
//	Solution s;
//	cout << s.maxProduct1(nums) << endl;
//	system("pause");
//	return 0;
//}