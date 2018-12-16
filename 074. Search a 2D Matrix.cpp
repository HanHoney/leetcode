//74. Search a 2D Matrix
//Medium
//Plan A: TC:O(logm+logn)
//Plan B: TC:O(m+n)

#include <iostream>
#include <vector>
using namespace std;

class Solution {

public:

	//从右上角开始
	//TC:O(m+n)
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int row = 0, col = matrix[0].size() - 1;
		while (row < matrix.size() && col >= 0) {
			if (matrix[row][col] == target) return true;
			if (matrix[row][col] < target) row++;
			else col--;
		}
		return false;
	}

	//从左下角开始
	//TC:O(m+n)
	bool serachMatrix1(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int row = matrix.size() - 1, col = 0;
		while (row >= 0 && col < matrix[0].size()) {
			if (matrix[row][col] == target) return true;
			if (matrix[row][col] > target) row--;
			else col++;
		}
		return false;
	}
};


int main() {
	vector<vector<int>> vec1{ {10,12},{15,20},{21,26} };
	vector<vector<int>> vec2{ {10,12},{15,20},{23,26} };
	vector<vector<int>> vec3{};
	vector<vector<int>> vec4{ {} };
	int tar = 21;
	Solution s;
	cout << s.searchMatrix(vec1, tar) << endl;
	cout << s.searchMatrix(vec2, tar) << endl;
	cout << s.searchMatrix(vec3, tar) << endl;
	cout << s.searchMatrix(vec4, tar) << endl;
	system("pause");
	return 0;
}
