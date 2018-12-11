//136. Single Number
//Easy
/*************************
�����٣�
	ʹ��list
		TC:O(n^2)
		SC:O(n

�����ڣ�
	ʹ��hash table
		TC:O(n)
		SC:O(n)

�����ۣ�
	��ѧ����
		TC:O(n)
		SC:O(n)

�����ܣ�
	λ����(���)
		TC:O(n)	
		SC:O(1)

�����ݣ�
	��sort����ɨ��
		TC:O(nlogn)
		SC:O(1)

*************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	//���
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
			if (nums[i] != nums[i - 1])  //����һ�ԱȽ�
				return nums[i - 1];
		}
		return nums.back();    //���������һ��Ԫ��
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