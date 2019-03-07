//268. Missing Number
//Easy

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		for (int i = 0; i<nums.size();) {
			if (nums[i]<nums.size() && i != nums[i]) {
				swap(nums[i], nums[nums[i]]);
			}
			else {
				i++;
			}
		}
		for (int i = 0; i<nums.size(); i++) {
			if (nums[i] != i) {
				return i;
			}
		}
		return nums.size();
	}
};