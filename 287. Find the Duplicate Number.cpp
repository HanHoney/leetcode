//287. Find the Duplicate Number
//Medium

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	//���μ�� �ο�142. Linked List Cycle II
	//��nums�е���ֵ1~n����ָ�����һ����index����ͬ��valueָ����ͬ����һ�ڵ㣬
	//������ת��Ϊ�����л��Ľ����ڲ��ң��ýڵ��Ӧ��index��Ϊ�ظ���valueֵ��
	//TC:O(n)  SC:O(1)
	int findDuplicate(vector<int>& nums) {
		if (nums.size() < 2) return -1;
		int slow = 0, fast = 0;
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);
		fast = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}

	//���ַ������ó���ԭ��
	//TC:O(nlogn)	SC:O(1)
	int findDuplicate(vector<int>& nums) {
		if (nums.size() < 2) return -1;
		int low = 1, high = nums.size() - 1;
		while (low < high) {
			int  mid = (low + high) / 2;
			int count = 0;
			for (int num : nums) {
				if (num <= mid) {
					count++;
				}
			}
			if (count > mid) {
				high = mid;
			}
			else {
				low = mid + 1;
			}
		}
		return low;
	}
};