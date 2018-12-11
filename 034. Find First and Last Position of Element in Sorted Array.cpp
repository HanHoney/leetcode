// 34. Find First and Last Position of Element in Sorted Array
// Medium

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		int m = (l + r) / 2;
		vector<int> init = { -1,-1 };
		vector<int> ret;
		if (nums.empty()) return init;
		if (nums.front() > target || nums.back() < target) return init;
		if (nums.front() == nums.back() && nums.front() == target) {
			return vector<int>{l, r};
		}
		while (l <= r) {
			if (nums[m] == target) {
				ret = { m,m };
				while (ret[0] > 0 && nums[ret[0] - 1] == target) {
					ret[0]--;
				}
				while (ret[1] < nums.size()-1 && nums[ret[1] + 1] == target) {
					ret[1]++;
				}
				return ret;
			}
			else if (nums[m] > target) {
				r = m - 1;
			}
			else if (nums[m] < target) {
				l = m + 1;
			}
			m = (l + r) / 2;    //¾ÓÈ»Íü¼ÇÕâ¾ä¡£¡£
		}
		return init;
	}
};

/*
int main() {
	Solution s;
	vector<int> nums = { 5,7,7,8,8,10 };
	vector<int> res = s.searchRange(nums, 8);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	system("pause");
}
*/