//556. Next Greater Element III
//Medium

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	// �Ӻ���ǰ��һ��˳��(x,y) x<y , 2 [ 3 4 ] 1  ��¼3��λ��:idx
	// 3����� [idx+1, size-1] ��Щ�����Ӻ���ǰ���ҵ�һ����3����������� => 2 4 3 1
	// [idx+1, size-1] ��Щ�� ���� => 2 4 1 3
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