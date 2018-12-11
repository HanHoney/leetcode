// 31. Next Permutation
// Medium

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2) return;
		for (int i = nums.size() - 1; i > 0; i--) {     //从后面开始遍历，找到第一对非逆序数，变成逆序即可增大
			if (nums[i - 1] < nums[i]) {
				int j = nums.size() - 1;                //依然从末尾开始遍历，找到最小的交换元素
				while (nums[i - 1] >= nums[j]) {
					j--;
				}
				swap(nums[j], nums[i - 1]);  
				sort(nums.begin() + i, nums.end());     //重新排列后面数字顺序
				return;
			}
		}
		sort(nums.begin(), nums.end());     //全部逆序，则重新排列即可
		return;
	}
};
