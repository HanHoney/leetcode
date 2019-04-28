//46. Permutations（排列）
//Medium
//若有下一个，则找出，并添加到结果集。复用nextPermutation()

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
#if 0
	vector<vector<int>> permute_1(vector<int>& nums) {
		vector<vector<int>> ret;
		vector<int> curr = nums;
		sort(curr.begin(), curr.end());
		ret.push_back(curr);
		while (nextPermutation(curr)) {
			ret.push_back(curr);
		}
		return ret;
	}
	bool nextPermutation(vector<int>& curr) {
		for (int i = curr.size() - 2; i >= 0; i--)  {
			if (curr[i + 1] > curr[i]) {             //从后遍历，寻找第一个可以交换的位置
				for (int j = curr.size() - 1; j > i; j--) {
					if (curr[j] > curr[i]) {
						swap(curr[i], curr[j]);
						sort(curr.begin() + i + 1, curr.end());
						return true;
					}
				}
			}
		}
		return false;
	}
#endif

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ret;
		if (nums.empty()) return ret;
		sort(nums.begin(), nums.end());
		dfs(ret, 0, nums);
		return ret;
	}
	void dfs(vector<vector<int>>& ret, int index, vector<int>& nums) {
		if (index == nums.size()) {
			ret.emplace_back(nums);
			return;
		}
		for (int i = index; i < nums.size(); ++i) {
			swap(nums[index], nums[i]);
			dfs(ret, index + 1, nums);
			swap(nums[index], nums[i]);
		}
	}
};