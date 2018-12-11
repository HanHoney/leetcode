// 31. Next Permutation
// Medium

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2) return;
		for (int i = nums.size() - 1; i > 0; i--) {     //�Ӻ��濪ʼ�������ҵ���һ�Է���������������򼴿�����
			if (nums[i - 1] < nums[i]) {
				int j = nums.size() - 1;                //��Ȼ��ĩβ��ʼ�������ҵ���С�Ľ���Ԫ��
				while (nums[i - 1] >= nums[j]) {
					j--;
				}
				swap(nums[j], nums[i - 1]);  
				sort(nums.begin() + i, nums.end());     //�������к�������˳��
				return;
			}
		}
		sort(nums.begin(), nums.end());     //ȫ���������������м���
		return;
	}
};
