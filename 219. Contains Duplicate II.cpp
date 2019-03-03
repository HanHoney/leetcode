//219. Contains Duplicate II
//Easy

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.empty()) return false;
		if (k <= 0) return false;
		unordered_set<int> s;
		if (k >= nums.size()) k = nums.size() - 1;
		for (int i = 0; i<nums.size(); i++) {
			if (i>k) s.erase(nums[i - k - 1]);
			if (s.find(nums[i]) != s.end()) {
				return true;
			}
			s.insert(nums[i]);
		}
		return false;
	}
};