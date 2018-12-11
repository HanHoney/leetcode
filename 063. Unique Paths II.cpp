//63. Unique Paths II
//Medium
//TC:O(mn) SC:O(mn)  
//��improved version��SC:O(n)

#include <vector>
using namespace std;

class Solution {
public:

	//SC:O(mn)
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> res(m, vector<int>(n, 0));

		//��һ�к͵�һ�еĽ����ʼ��
		for (int i = 0; i < n; i++) {
			if (obstacleGrid[0][i] != 1)     //�������ϰ�֮ǰ������ֵΪ1
				res[0][i] = 1;
			else break;
		}
		for (int i = 0; i < m; i++) {
			if (obstacleGrid[i][0] != 1)      
				res[i][0] = 1;
			else break;
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) {   //�����ϰ�
					res[i][j] = 0;
				}
				else {
					res[i][j] = res[i - 1][j] + res[i][j - 1];
				}
			}
		}
		return res[m - 1][n - 1];
	}


	//SC:O(n)
	int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<int> res(n, 0);

		//��һ�еĽ����ʼ��
		for (int i = 0; i < n; i++) {
			if (obstacleGrid[0][i] != 1)     //�������ϰ�֮ǰ������ֵΪ1
				res[i] = 1;
			else break;
		}
		for (int i = 1; i < m; i++) {
			res[0] = obstacleGrid[i][0] == 1 ? 0 : res[0];
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) {   //�����ϰ�
					res[j] = 0;
				}
				else {
					res[j] += res[j - 1];
				}
			}
		}
		return res[n - 1];
	}
};