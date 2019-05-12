//73. Set Matrix Zeroes
//Medium
//TC:O(mn) SC:O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	//SC:O(1)
	//把每一个0都传递到第一行和第一列
	//matrix[0][j]记录第一行信息，matrix[0][0]记录行信息
	//matrix[i][0]记录第一列信息，matrix[0][0]不记录列信息，列信息单独记录
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		bool firstColZero = false;

		//按行扫描，每行第一列单独记录，matrix[0][0]记录第一行元素，一个空间不能同时记录行列信息。
		for (int i = 0; i < m; i++) {
			if (matrix[i][0] == 0) firstColZero = true;
			for (int j = 1; j < n; j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		/*
		//没有信息的普通位置，根据行和列的记录信息更新
		for (int i = 1; i < m; i++) {    
			for (int j = 1; j < n; j++) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
		//第一行是否更新为0
		if (matrix[0][0] == 0) {
			for (int i = 0; i < n; i++) {
				matrix[0][i] = 0;
			}
		}
		//第一列是否更新为0
		if (firstColZero) {
			for (int i = 0; i < m; i++) {
				matrix[i][0] = 0;
			}
		}
		*/

		for (int i = m - 1; i >= 0; i--) {
			for (int j = n - 1; j > 0; j--) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
			if (firstColZero) matrix[i][0] = 0;
		}
	}

	//SC:O(m+n)
	void setZeroes_1(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		vector<bool> row(m, false);
		vector<bool> col(n, false);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0) {
					row[i] = true;
					col[j] = true;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (row[i] || col[j]) {
					matrix[i][j] = 0;
				}
			}
		}
	}
};

/*
int main() {
	vector<vector<int>> vec{ {1,2,0,4},{3,1,2,4}, {2,1,0,4},{1,1,1,1} };
	Solution s;
	s.setZeroes(vec);
	for (const auto &v : vec) {
		for (auto i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
*/

