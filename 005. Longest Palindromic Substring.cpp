//5. Longest Palindromic Substring(最长回文子串)
//Medium
//DP
//dp[i][j]==s[i]==s[j]&&dp[i+1][j-1],dp[i][i]=true,dp[i][i+1]=true when s[i]==s[i+1]
//i依赖于i+1,j依赖于j-1，所以i递减,j递增。


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		if (n <= 1) return s;
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		int left = 0;
		int mlen = 1;
		for (int i = 0; i < n; ++i) {
			dp[i][i] = true;
			if (i > 0 && s[i] == s[i - 1]) {
				dp[i - 1][i] = true;
				left = i - 1;
				mlen = 2;
			}
		}
		for (int i = n - 3; i >= 0; --i) {
			for (int j = i + 2; j < n; ++j) {
				if (s[i] == s[j] && dp[i + 1][j - 1]) {
					dp[i][j] = true;
					if (j - i + 1 > mlen) {
						left = i;
						mlen = j - i + 1;
					}
				}
			}
		}
		return s.substr(left, mlen);
	}
};

#if 0
int main() {
	string str("babab");
	Solution s;
	cout << s.longestPalindrome(str) << endl;
	system("pause");
	return 0;
}
#endif