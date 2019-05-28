//52. N - Queens II
//Hard

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		int ret = 0;
		vector<bool> col(n, false);
		vector<bool> mainDiag(2 * n - 1, false);
		vector<bool> deputyDiag(2 * n - 1, false);
		dfs(ret, 0, n, col, mainDiag, deputyDiag);
		return ret;
	}
	void dfs(int &ret, int idx, int n, vector<bool> &col, vector<bool> &mainDiag, vector<bool> &deputyDiag) {
		if (idx == n) {
			++ret;
			return;
		}
		for (int i = 0; i < n; ++i) {
			if (!col[i] && !mainDiag[n - 1 - idx + i] && !deputyDiag[idx + i]) {
				col[i] = true;
				mainDiag[n - 1 - idx + i] = true;
				deputyDiag[idx + i] = true;
				dfs(ret, idx + 1, n, col, mainDiag, deputyDiag);
				col[i] = false;
				mainDiag[n - 1 - idx + i] = false;
				deputyDiag[idx + i] = false;
			}
		}
	}
};