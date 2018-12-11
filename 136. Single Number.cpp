//136. Single Number
//Easy
/*************************
方法①：
	使用list
		TC:O(n^2)
		SC:O(n

方法②：
	使用hash table
		TC:O(n)
		SC:O(n)

方法③：
	数学方法
		TC:O(n)
		SC:O(n)

方法④：
	位运算(异或！)
		TC:O(n)	
		SC:O(1)

方法⑤：
	先sort，再扫描
		TC:O(nlogn)
		SC:O(1)

*************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	//异或
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (auto n : nums) {
			ret ^= n;
		}
		return ret;
	}

	//sort
	int singleNumber1(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); i += 2) {
			if (nums[i] != nums[i - 1])  //两两一对比较
				return nums[i - 1];
		}
		return nums.back();    //否则是最后一个元素
	}
};
//
//int main() {
//	vector<int> nums{ 2,4,1,2,1 };
//	Solution s;
//	cout << s.singleNumber(nums) << endl;
//	cout << s.singleNumber1(nums) << endl;
//	system("pause");
//	return 0;
//}