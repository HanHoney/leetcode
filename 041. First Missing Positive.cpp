//41. First Missing Positive
//Hard
//TC:O(n) SC:O(1)
//一次遍历 swap
//一次遍历 return


#include <vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			while (nums[i] > 0 && nums[i] < n + 1 && nums[i] != nums[nums[i] - 1])  //注意while，最后一个条件在保证已经正位的元素不变的同时，避免相同元素不断交换
				swap(nums[i], nums[nums[i] - 1]);
		}
		for (int i = 0; i < n; i++) {
			if (nums[i] != i + 1)
				return i + 1;
		}
		return n + 1;
	}
};