//48. Rotate Image
//Medium(in-place)

//B[j][n-i-1]=A[i][j]，逆时针90°clockwise
//为了保证空间复杂度为O(1)，变换是保证是两两交换
//C[i][i]=A[i][j],B[j][n-i-1]=C[j][i]  变化两次
//顺时针：先算行对称(reverse)，再求转置
//逆时针：先求转置，再算行对称

#include <vector>
using namespace std;
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix[0].size();
		if (n < 2) return;
		for (int i = 0; i < n - 1; i++) {    //上三角（不含对角线）
			for (int j = i + 1; j < n; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		for (int i = 0; i < n; i++) {        //左半部分
			for (int j = 0; j < n / 2; j++) {
				swap(matrix[i][j], matrix[i][n - j - 1]);
			}
		}
		return;
	}

	void rotate1(vector<vector<int>>& matrix) {
		int n = matrix[0].size();
		if (n < 2) return;
		reverse(matrix.begin(), matrix.end());   //先行对称，再算转置矩阵
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		return;
	}
};