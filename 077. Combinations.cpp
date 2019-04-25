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
		vector<vector<int>> ret;
		if (k > n || k <= 0) return ret;
		vector<int> path;
		dfs(ret, path, 0, k, n);
		return ret;
	}

private:
	void dfs(vector<vector<int>>& ret, vector<int>& path, int prev, int k, int n) {
		if (k == 0) {
			ret.emplace_back(path);
			return;
		}
		for (int i = prev + 1; i <= n - k + 1; ++i) {	//注意这个范围，剪枝，否则会TLE
			path.emplace_back(i);
			dfs(ret, path, i, k - 1, n);
			path.pop_back();
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