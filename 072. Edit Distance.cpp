//72. Edit Distance(��̱༭����)
//Hard
//DP������Ŀ

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		if (m == 0) return n;
		if (n == 0) return m;
		vector<vector<int>> res(m + 1, vector<int>(n + 1, INT_MAX));   
		for (int i = 0; i <= m; i++) {   //����ַ�����ƥ����
			res[i][0] = i;
		}
		for (int i = 0; i <= n; i++) {
			res[0][i] = i;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				res[i][j] = min(min(res[i - 1][j] + 1, res[i][j - 1] + 1), res[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1));  
				//ע���Ӧ��word1��word2�±꣬�Լ����ʽ���ж��������ţ������������ӷ���
			}
		}
		return res[m][n];
	}
};
//
//int main() {
//	string w1("abc");
//	string w2("acd");
//	Solution s;
//	int ans = s.minDistance(w1, w2);
//	cout << ans << endl;
//	system("pause");
//	return 0;
//}