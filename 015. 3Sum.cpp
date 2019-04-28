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
		int n = nums.size();
		if (n < 3) {
			return ret;
		}
		sort(nums.begin(), nums.end());
		if (nums.front() > 0 || nums.back() < 0) {
			return ret;
		}
		for (int i = 0; i < n - 2; ++i) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int j = i + 1;
			int k = n - 1;
			while (j < k) {
				if (nums[i] + nums[j] + nums[k] == 0) {
					ret.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
					++j;
					--k;
					while (j < k&&nums[j] == nums[j - 1]) {
						++j;
					}
					while (j < k&&nums[k] == nums[k + 1]) {
						--k;
					}
				}
				else if (nums[i] + nums[j] + nums[k] > 0) {
					--k;
					while (j < k&&nums[k] == nums[k + 1]) {
						--k;
					}
				}
				else {
					++j;
					while (j < k&&nums[j] == nums[j - 1]) {
						++j;
					}
				}
			}
		}
		return ret;
	}
};

//
//int main() {
//	vector<int> nums{ -1,0,1,2,-1,-4 };
//	Solution s;
//	vector<vector<int>> result = s.threeSum(nums);
//	for (auto &v : result) {
//		for (auto n : v) {
//			cout << n << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}