//26. Remove Duplicates from Sorted Array
//�ڳ��ȷ�Χ֮���Ԫ��ֵ��Ӱ����������Ĳ�ͬԪ����ǰ�ƶ�����֮ǰ��Ԫ��

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int index = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[index - 1]) {
				nums[index++] = nums[i];
			}
		}
		return index;
	}
};