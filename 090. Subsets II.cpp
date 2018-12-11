//90. Subsets II
//Medium
//①非递归 ②递归
/* http://www.cnblogs.com/TenosDoIt/p/3451902.html */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		vector<vector<int>> ret(1);
		if (nums.empty()) return ret;
		sort(nums.begin(), nums.end());
		int lastNum = nums[0];			//上一个元素
		int cnt = 1;					//记录此轮操作要在几个子集的基础上insert产生新子集。
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != lastNum) {	//新的元素，更新两个标记。
				lastNum = nums[i];
				cnt = ret.size();
			}
			//若与上一个元素一样，只需要在上一轮新产生的子集中添加形成新的元素。
			int size = ret.size();
			for (int j = size - cnt; j < size; j++) {
				ret.push_back(ret[j]);
				ret.back().push_back(nums[i]);
			}
		}
		return ret;
	}

	vector<vector<int>> subsetsWithDup1(vector<int> &nums) {
		vector<vector<int>> ret;
		vector<int> tmp;
		sort(nums.begin(), nums.end());
		dfs(ret, tmp, nums, 0);
		return ret;
	}
	void dfs(vector<vector<int>> &ret, vector<int> &tmp, vector<int> &nums, int idx) {
		if (idx == nums.size()) {
			ret.push_back(tmp);
			return;
		}
		//不选择nums[idx]
		dfs(ret, tmp, nums, idx + 1);

		int cnt = 0;		//当前元素以前出现的次数，即要变动的子集中含有该元素的个数。
		while (idx - cnt >= 0 && nums[idx - cnt] == nums[idx]) cnt++;
		cnt--;
		if (cnt == 0 || tmp.size() >= cnt && tmp[tmp.size() - cnt] == nums[idx]) {
			//选择nums[idx]
			tmp.push_back(nums[idx]);
			dfs(ret, tmp, nums, idx + 1);
			tmp.pop_back();
		}
	}
};
//
//int main() {
//	vector<int> nums{ 1,2,2 };
//	Solution s;
//	vector<vector<int>> res = s.subsetsWithDup1(nums);
//	for (auto &v : res) {
//		cout << "[ ";
//		for (auto n : v) {
//			cout << n << " ";
//		}
//		cout << "]" << endl;
//	}
//	system("pause");
//	return 0;
//}

