//44. Wildcard Matching
//通配符匹配
//Hard
//【DP】

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isMatch(string s,string p) {
		int m = s.size();
		int n = p.size();
		if (m == 0 && n == 0) return true;
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));  //dp[i][j]:s的前i个字符和p的前j个字符是否匹配
		dp[0][0] = true;
		for (int i = 0; i < n && p[i] == '*'; i++) {
			dp[0][i + 1] = true;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 1] || dp[i - 1][j];  //'*'代表0个字符或者'*'再多代表一个字符
				}
				else {
					dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
				}
			}
		}
		return dp[m][n];
	}
};