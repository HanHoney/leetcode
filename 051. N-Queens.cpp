//51. N-Queens
//Hard
//DFS

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> ret;
		vector<string> path(n, string(n, '.'));
		//n个行,n个列,2*n-1个左斜线,2*n-1个右斜线.按行dfs试错
		vector<bool> col(n, false);
		vector<bool> mainDiag(2 * n - 1, false);    //idx=(n-1-x)+y
		vector<bool> deputyDiag(2 * n - 1, false);  //idx=x+y
		dfs(ret, path, 0, n, col, mainDiag, deputyDiag);
		return ret;
	}

	void dfs(vector<vector<string>> &ret, vector<string> &path, int idx, int n, vector<bool> &col, vector<bool> &mainDiag, vector<bool> &deputyDiag) {
		if (idx == n) {
			ret.emplace_back(path);
			return;
		}
		for (int i = 0; i < n; ++i) {
			if (!col[i] && !mainDiag[n - 1 - idx + i] && !deputyDiag[idx + i]) {
				col[i] = true;
				mainDiag[n - 1 - idx + i] = true;
				deputyDiag[idx + i] = true;
				path[idx][i] = 'Q';
				dfs(ret, path, idx + 1, n, col, mainDiag, deputyDiag);
				path[idx][i] = '.';
				col[i] = false;
				mainDiag[n - 1 - idx + i] = false;
				deputyDiag[idx + i] = false;
			}
		}
	}
};