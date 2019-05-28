//240. Search a 2D Matrix II
//Medium
//������Ŀ��074��
//TC:O(m+n)		SC:O(1)
//���ܶ��ֲ��ң�ֻ��ÿ�ζ��л�����++����--�ĸı�

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	
	//�����Ͻǿ�ʼ
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

	//�����½ǿ�ʼ
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
//
//int main() {
//	int tar1 = 16;
//	int tar2 = 25;
//	vector<vector<int>> vec{ {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
//	Solution s;
//	cout << s.searchMatrix(vec, tar1) << endl;
//	cout << s.searchMatrix(vec, tar2) << endl;
//	system("pause");
//	return 0;
//}