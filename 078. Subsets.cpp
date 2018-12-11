//78. Subsets
//Medium
//本题不要求子集内部元素非降序排列，不需要sort()
//①非递归 ②递归 ③匹配二进制位？
/* http://www.cnblogs.com/TenosDoIt/p/3451902.html */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	//①非递归
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ret(1);               //初始化，只有一个空集
		if (nums.empty()) return ret;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {   //依次添加每个数字
			int len = ret.size();
			for (int j = 0; j < len; j++) {       //将该数字添加到所有已有的子集中，并与之前的子集形成新的子集
				ret.push_back(ret[j]);
				ret.back().push_back(nums[i]);
			}
		}
		return ret;
	}

	//②递归（DFS）
	//二叉树，每个元素都有选和不选两种操作。
	vector<vector<int>> subsets1(vector<int>& nums) {
		vector<vector<int>> ret;
		vector<int> tmp;
		sort(nums.begin(), nums.end());
		dfs(ret, tmp, nums, 0);
		return ret;
	}
	void dfs(vector<vector<int>> &ret, vector<int> &tmp, vector<int> &nums, int i) {
		if (i == nums.size()) {   //叶子结点
			ret.push_back(tmp);
			return;
		}
		/*
		//选择nums[i]
		tmp.push_back(nums[i]);
		dfs(ret, tmp, nums, i + 1);
		//不选择nums[i]
		tmp.pop_back();
		dfs(ret, tmp, nums, i + 1);
		*/
		
		//不选择nums[i]
		dfs(ret, tmp, nums, i + 1);
		//选择nums[i]
		tmp.push_back(nums[i]);
		dfs(ret, tmp, nums, i + 1);
		//rollback
		tmp.pop_back();
	}

	//③二进制
	//TRUE FALSE对应二进制位？？

};

//
//int main() {
//	vector<int> nums{ 1,2,3 };
//	vector<vector<int>> res;
//	Solution s;
//	res = s.subsets1(nums);
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