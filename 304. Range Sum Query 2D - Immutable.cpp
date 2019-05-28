//304. Range Sum Query 2D - Immutable
//Medium

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix) {
		row = matrix.size();
		col = row == 0 ? 0 : matrix[0].size();
		sums = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + matrix[i][j];
			}
		}
	}
	int sumRegion(int row1, int col1, int row2, int col2) {
		return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
	}

private:
	int row;
	int col;
	vector<vector<int>> sums;
};

//
//int main() {
//	vector<vector<int>> nums{ {3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5} };
//	NumMatrix mt(nums);
//	cout << mt.sumRegion(2, 1, 4, 3) << endl;
//	cout << mt.sumRegion(1, 1, 2, 2) << endl;
//	cout << mt.sumRegion(1, 2, 2, 4) << endl;
//	system("pause");
//	return 0;
//}
