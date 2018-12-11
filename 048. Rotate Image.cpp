//48. Rotate Image
//Medium(in-place)

//B[j][n-i-1]=A[i][j]����ʱ��90��clockwise
//Ϊ�˱�֤�ռ临�Ӷ�ΪO(1)���任�Ǳ�֤����������
//C[i][i]=A[i][j],B[j][n-i-1]=C[j][i]  �仯����
//˳ʱ�룺�����жԳ�(reverse)������ת��
//��ʱ�룺����ת�ã������жԳ�

#include <vector>
using namespace std;
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix[0].size();
		if (n < 2) return;
		for (int i = 0; i < n - 1; i++) {    //�����ǣ������Խ��ߣ�
			for (int j = i + 1; j < n; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		for (int i = 0; i < n; i++) {        //��벿��
			for (int j = 0; j < n / 2; j++) {
				swap(matrix[i][j], matrix[i][n - j - 1]);
			}
		}
		return;
	}

	void rotate1(vector<vector<int>>& matrix) {
		int n = matrix[0].size();
		if (n < 2) return;
		reverse(matrix.begin(), matrix.end());   //���жԳƣ�����ת�þ���
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		return;
	}
};