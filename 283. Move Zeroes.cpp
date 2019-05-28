//283. Move Zeroes
//Easy
//two pointers
//TC:O(n)	SC:O(1) in-place

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		for (int i = 0, j = 0; j < nums.size(); j++) {
			if (nums[j] != 0) {
				swap(nums[i++], nums[j]);
			}
		}
	}
	/*
	void moveZeroes1(vector<int>& nums) {
		if (nums.empty()) return;
		int cnt = 0;
		for (auto n : nums) {
			if (n == 0) cnt++;
		}
		if (cnt == 0) return;
		int idx = 0;
		for (auto n : nums) {
			if (n != 0) {
				nums[idx++] = n;
			}
		}
		for (int i = idx; i < nums.size(); i++) {
			nums[i] = 0;
		}
	}
	*/
};
//
//int main() {
//	Solution s;
//	vector<int> nums{ 0,1,0,3,12 };
//	s.moveZeroes(nums);
//	for (auto n : nums) {
//		cout << n << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}