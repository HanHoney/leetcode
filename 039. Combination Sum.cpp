//39. Combination Sum
//Medium
//回溯法，DFS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ret;    //最终结果
		if (candidates.size() <= 0) return ret;
		vector<int> curr;			//中间结果
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, curr, 0, ret);
		return ret;
	}

private:
	void dfs(vector<int>& candidates, int target, vector<int> &curr, int index, vector<vector<int>> &ret) {
		if (target == 0) {			//找到一个合法解
			ret.push_back(curr);
			return;
		}
		for (int i = index; i < candidates.size(); i++) {
			if (target < candidates[i]) return; //剪枝
			curr.push_back(candidates[i]);      //执行扩展动作
			dfs(candidates, target - candidates[i], curr, i, ret);
			curr.pop_back();					//撤销动作
		}
	}
};
//
//int main() {
//	vector<int> cdds{ 2,3,5 };
//	int target = 8;
//	Solution s;
//	vector<vector<int>> res = s.combinationSum(cdds, target);
//	for (auto &v : res) {
//		cout << "[ ";
//		for (auto n : v) {
//			cout << n << " ";
//		}
//		cout << "]\n";
//	}
//	system("pause");
//	return 0;
//}