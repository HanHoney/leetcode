//75. Sort Colors
//Medium
//��two-pass ��one-pass

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	//two-pass
	//��һ�飺����	�ڶ��飺��д
	void sortColors(vector<int>& nums) {
		if (nums.empty()) return;
		int redCnt = 0, whiteCnt = 0, blueCnt = 0;
		for (auto n : nums) {
			if (n == 0) redCnt++;
			else if (n == 1) whiteCnt++;
			else blueCnt++;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (i < redCnt) nums[i] = 0;
			else if (i < redCnt + whiteCnt) nums[i] = 1;
			else nums[i] = 2;
		}
	}

	//one-pass
	//ɨ��+����
	void sortColors1(vector<int>& nums) {
		if (nums.empty()) return;
		int left = 0, right = nums.size() - 1;   //[left,i)��ΧֵΪ1��[0,left)Ϊ0��(right,n-1]Ϊ2��[i,right]δ���򡣡�left<=i��
		for (int i = 0; i <= right; i++) {       //��i<=right��
			if (nums[i] == 0) swap(nums[i], nums[left++]);
			else if (nums[i] == 2) swap(nums[i--], nums[right--]);   //swap֮���µ�nums[i]����Ҫ�ж�
		}
	}
};

//
//int main() {
//	vector<int> vec{ 0,2,1,2,0,1,1,0 };
//	Solution s;
//	s.sortColors1(vec);
//	for (auto a : vec)
//		cout << a << " ";
//	cout << endl;
//	system("pause");
//	return 0;
//}