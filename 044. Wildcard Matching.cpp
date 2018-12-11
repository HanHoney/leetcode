//44. Wildcard Matching
//ͨ���ƥ��
//Hard
//��DP��

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isMatch(string s,string p) {
		int m = s.size();
		int n = p.size();
		if (m == 0 && n == 0) return true;
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));  //dp[i][j]:s��ǰi���ַ���p��ǰj���ַ��Ƿ�ƥ��
		dp[0][0] = true;
		for (int i = 0; i < n && p[i] == '*'; i++) {
			dp[0][i + 1] = true;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 1] || dp[i - 1][j];  //'*'����0���ַ�����'*'�ٶ����һ���ַ�
				}
				else {
					dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
				}
			}
		}
		return dp[m][n];
	}
};