//77. Combinations
//Medium
//DFS，否则要k重循环
//n个选k个，组合问题

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	vector<vector<int>> combine(int n, int k) {		
		vector<vector<int>> ret;	//最终结果
		if (n < k || k <= 0) return ret;
		vector<int> path;			//中间结果
		dfs(ret, path, 1, n, k);
		return ret;
	}

private:
	void dfs(vector<vector<int>> &ret, vector<int> &path, int curr, int n, int k) {
		if (k == 0) {					//找到一个合法解
			ret.push_back(path);
			return;
		}
		for (int i = curr; i <= n - k + 1; i++) {   //剪枝，i <= n 也可以
			path.push_back(i);			//执行扩展动作
			dfs(ret, path, i + 1, n, k - 1);
			path.pop_back();			//撤销动作
		}
	}
};

//
//int main() {
//	vector<vector<int>> ans;
//	Solution s;
//	ans = s.combine(6, 3);
//	for (auto &a : ans) {
//		cout << "[ ";
//		for (auto d : a) {
//			cout << d << " ";
//		}
//		cout << "]\n";
//	}
//	system("pause");
//	return 0;
//}