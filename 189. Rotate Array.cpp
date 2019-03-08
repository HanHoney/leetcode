//189. Rotate Array
//Easy
//rorate => reverse
// (XY)'=Y'X',(Y')'(X')'=YX

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.size() < 2) return;
		k %= nums.size();
		if (k == 0) return;
		reverse(nums, 0, nums.size() - 1);
		reverse(nums, 0, k - 1);
		reverse(nums, k, nums.size() - 1);
	}
	void reverse(vector<int>& nums, int begin, int end) {
		while (begin < end) {
			swap(nums[begin++], nums[end--]);
		}
	}
};