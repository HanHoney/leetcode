//15. 3Sum
//Medium

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		if (nums.size() < 3)
			return ret;
		sort(nums.begin(), nums.end());             //�����ӶȽ���O(n^2)
		if (nums.front() > 0 || nums.back() < 0)    //����Ԫ��ͬ�ţ�û�з���Ҫ�����Ԫ��
			return ret;
		int n = nums.size();
		for (int i = 0; i < n - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1])    //��ͬ��Ԫ�أ�ֻ��Ҫʹ�õ�һ��
				continue;
			int a = nums[i];
			int low = i + 1;
			int high = n - 1;
			while (low < high) {
				int b = nums[low];
				int c = nums[high];
				if (a + b + c == 0) {
					ret.push_back({a,b,c});
					while (low < n - 1 && nums[low + 1] == nums[low]) {    //������ͬ��Ԫ��
						low++;
					}
					while (high > i + 1 && nums[high - 1] == nums[high]) {
						high--;
					}
					low++;
					high--;
				}
				else if (a + b + c > 0) {
					while (high > i + 1 && nums[high - 1] == nums[high]) {
						high--;
					}
					high--;
				}
				else {
					while (low < n - 1 && nums[low + 1] == nums[low]) {    //������ͬ��Ԫ��
						low++;
					}
					low++;
				}
			}
		}
		return ret;
	}
};


int main() {
	vector<int> nums{ -1,0,1,2,-1,-4 };
	Solution s;
	vector<vector<int>> result = s.threeSum(nums);
	for (auto &v : result) {
		for (auto n : v) {
			cout << n << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}