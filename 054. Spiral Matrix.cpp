//54. Spiral Matrix
//Medium
//模拟~

#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
		if (matrix.empty()) return ret;
		int mMin = 0, nMin = 0;
		int mMax = matrix.size() - 1;
		int nMax = matrix[0].size() - 1;
		for (; (mMin < mMax) && (nMin < nMax); mMin++, mMax--, nMin++, nMax--) {  //先将外圈去掉
			for (int i = nMin; i < nMax; i++) {
				ret.push_back(matrix[mMin][i]);
			}
			for (int i = mMin; i < mMax; i++) {
				ret.push_back(matrix[i][nMax]);
			}
			for (int i = nMax; i > nMin; i--) {
				ret.push_back(matrix[mMax][i]);
			}
			for (int i = mMax; i > mMin; i--) {
				ret.push_back(matrix[i][nMin]);
			}
		}
		if (mMin == mMax) {   //一行或单独一个
			for (int i = nMin; i <= nMax; i++) {
				ret.push_back(matrix[mMin][i]);
			}
		}
		else if (nMin == nMax) {   //一列
			for (int i = mMin; i <= mMax; i++) {
				ret.push_back(matrix[i][nMin]);
			}
		}
		return ret;
	}
};