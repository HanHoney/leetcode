//41. First Missing Positive
//Hard
//TC:O(n) SC:O(1)
//һ�α��� swap
//һ�α��� return


#include <vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			while (nums[i] > 0 && nums[i] < n + 1 && nums[i] != nums[nums[i] - 1])  //ע��while�����һ�������ڱ�֤�Ѿ���λ��Ԫ�ز����ͬʱ��������ͬԪ�ز��Ͻ���
				swap(nums[i], nums[nums[i] - 1]);
		}
		for (int i = 0; i < n; i++) {
			if (nums[i] != i + 1)
				return i + 1;
		}
		return n + 1;
	}
};