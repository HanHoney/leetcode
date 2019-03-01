//287. Find the Duplicate Number
//Medium

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	//环形检测 参考142. Linked List Cycle II
	//将nums中的数值1~n看作指向的下一结点的index，相同的value指向相同的下一节点，
	//则问题转化为链表中环的结点入口查找，该节点对应的index即为重复的value值。
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

	//二分法，利用抽屉原理
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