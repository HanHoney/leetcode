//442. Find All Duplicates in an Array
//Medium

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> ret;
		for (int i = 0; i < nums.size(); i++) {
			int idx = abs(nums[i]) - 1;
			if (nums[idx] > 0) {
				nums[idx] = -nums[idx];
			}
			else {
				ret.push_back(idx + 1);
			}
		}
		return ret;
	}
};