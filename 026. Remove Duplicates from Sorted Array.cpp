//26. Remove Duplicates from Sorted Array
//在长度范围之外的元素值不影响结果，后面的不同元素往前移动覆盖之前的元素

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int index = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[index - 1]) {
				nums[index++] = nums[i];
			}
		}
		return index;
	}
};