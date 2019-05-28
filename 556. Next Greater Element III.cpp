//556. Next Greater Element III
//Medium

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	// 从后往前第一对顺序(x,y) x<y , 2 [ 3 4 ] 1  记录3的位置:idx
	// 3后面的 [idx+1, size-1] 这些数，从后往前，找第一个比3大的数，交换 => 2 4 3 1
	// [idx+1, size-1] 这些数 排序 => 2 4 1 3
	int nextGreaterElement(int n) {
		vector<int> nums;
		while (n) {
			nums.emplace_back(n % 10);
			n /= 10;
		}
		int size = nums.size();
		int left = 0, right = size - 1;
		while (left < right) {
			swap(nums[left++], nums[right--]);
		}
		int idx = -1;
		for (int i = size - 2; i >= 0; --i) {
			if (nums[i] < nums[i + 1]) {
				idx = i;
				break;
			}
		}
		if (idx == -1) return -1;
		for (int i = size - 1; i > idx; --i) {
			if (nums[i] > nums[idx]) {
				swap(nums[i], nums[idx]);
				sort(nums.begin() + idx + 1, nums.end());
				break;
			}
		}
		long long ret = 0;
		for (int num : nums) {
			ret = ret * 10 + num;
		}
		if (ret > static_cast<long long>(INT_MAX)) return -1;
		else return static_cast<int>(ret);
	}
};