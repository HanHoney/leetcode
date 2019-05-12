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

	//TC:O(mn)	SC:O(mn)
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

	//TC: O(mn)	SC:O(min(m,n))
	int minDistance_better(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		if (m > n) return minDistance(word2, word1);
		if (n == 0) return m;
		vector<int> dp(n + 1);
		for (int i = 0; i <= n; ++i) {
			dp[i] = i;
		}
		int prev;
		for (int i = 1; i <= m; ++i) {
			prev = dp[0];
			dp[0] = i;
			for (int j = 1; j <= n; ++j) {
				int tmp = dp[j];
				dp[j] = min(min(dp[j] + 1, dp[j - 1] + 1), prev + (word1[i - 1] == word2[j - 1] ? 0 : 1));		//ע���������ʽ�����ţ�
				prev = tmp;
			}
		}
		return dp[n];
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