//448. Find All Numbers Disappeared in an Array
//Easy
//Similar Questions:442

/*
数组中数的范围和下标一致时，可以考虑用数值表示下一节点的索引值
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> ret;
		for (int i = 0; i < nums.size(); i++) {
			int idx = abs(nums[i]) - 1;
			if (nums[idx] > 0) {
				nums[idx] = -nums[idx];
			}
		}
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) {
				ret.push_back(i + 1);
			}
		}
		return ret;
	}
};