//80. Remove Duplicates from Sorted Array II
//Medium

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2)
			return nums.size();
		int prev = nums[0];
		int cnt = 1;
		for (int i = 1; i<nums.size();) {
			if (nums[i] != prev) {
				cnt = 1;
				prev = nums[i];
			}
			else {
				cnt++;
			}
			if (cnt>2) {
				int j = i + 1;
				while (j<nums.size() && nums[j] == prev) {
					j++;
				}
				nums.erase(nums.begin() + i, nums.begin() + j);
			}
			else {
				i++;
			}
		}
		return nums.size();
	}
	*/

	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2)
			return nums.size();
		int index = 2;
		for (int i = 2; i < nums.size(); i++) {
			if (nums[i] != nums[index - 2]) {
				nums[index++] = nums[i];
			}
		}
		return index;
	}
};
