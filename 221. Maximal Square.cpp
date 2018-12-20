//221. Maximal Square
//Medium

/*和85题不同，题目要求是正方形*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	//TC:O(mn)	SC:O(mn)
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty())return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		int size = 0;
		vector<vector<int>> dp(m, vector<int>(n,0));	//以matrix[i][j]为右下角的最大正方形边长
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '1') {
					if (i&&j) {
						dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
					}
					else {
						dp[i][j] = 1;
					}
					size = max(size, dp[i][j]);
				}
			}
		}
		return size * size;
	}

	//优化
	//TC:O(mn) SC:O(m)orO(n)
	int maximalSquare1(vector<vector<char>>& matrix) {
		if (matrix.empty())return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		int size = 0;
		vector<int> prev(n, 0);
		vector<int> curr(n, 0);
		for (int i = 0; i < n; i++) {
			prev[i] = matrix[0][i] - '0';
			size = max(size, prev[i]);
		}
		for (int i = 1; i < m; i++) {		//按行更新，也可以按列更新
			curr[0] = matrix[i][0] - '0';
			size = max(size, curr[0]);
			for (int j = 1; j < n; j++) {
				if (matrix[i][j] == '1') {
					curr[j] = min(min(prev[j - 1], prev[j]), curr[j - 1]) + 1;
					size = max(size, curr[j]);
				}
				else curr[j] = 0;
			}
			prev = curr;
		}
		return size * size;
	}

	//进一步优化:use only one vector
	//TC:O(mn)	SC:O(m)或O(n)
	int maximalSquare2(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		int size = 0;
		int prev = 0;
		vector<int> dp(n, 0);
		for (int i = 0; i < n; i++) {
			dp[i] = matrix[0][i] - '0';
			size = max(size, dp[i]);
		}
		for (int i = 1; i < m; i++) {
			prev = dp[0];
			dp[0] = matrix[i][0] - '0';
			size = max(size, dp[0]);
			for (int j = 1; j < n; j++) {
				int tmp = dp[j];
				if (matrix[i][j] == '1') {
					dp[j] = min(min(dp[j - 1], dp[j]), prev) + 1;
					size = max(size, dp[j]);
				}
				else dp[j] = 0;
				prev = tmp;
			}
		}
		return size * size;
	}
};


int main() {
	vector<vector<char>> m{ { '1','0','1','0','0' },{ '1','0','1','1','1' },{ '1','1','1','1','1' },{ '1','0','0','1','0' } };
	Solution s;
	cout << s.maximalSquare(m) << endl;
	cout << s.maximalSquare1(m) << endl;
	cout << s.maximalSquare2(m) << endl;
	system("pause");
	return 0;
}