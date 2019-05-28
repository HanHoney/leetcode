//169. Majority Element
//Easy

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

	//该数字出现次数减去其他数字出现次数 > 0
	//TC:O(n)	SC:O(1)
	int majorityElement(vector<int>& nums) {
		int ret;
		int count = 0;
		for (auto n : nums) {
			if (count == 0) {
				ret = n;
				count = 1;
			}
			else ret == n ? count++ : count--;
		}
		return ret;
	}

	//哈希表
	//TC:O(n)	SC:O(n)
	int majorityElement1(vector<int>& nums) {
		unordered_map<int, int> map;
		for (auto n : nums) {
			map[n]++;
			if (map[n] > nums.size() / 2) return n;
		}
	}
};

//
//int main() {
//	vector<int> nums{ 1,2,3,2,4,2,1,2,2 };
//	Solution s;
//	cout << s.majorityElement(nums) << endl;
//	cout << s.majorityElement1(nums) << endl;
//	system("pause");
//	return 0;
//}