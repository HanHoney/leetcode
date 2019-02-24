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
	string findPalindrome(string str,int left,int right) {
		int n = str.size();
		while (left >= 0 && right <= n - 1 && str[left] == str[right]) {    //向左右扩展
			left--;
			right++;
		}
		return str.substr(left + 1, right - left - 1);
	}
	string longestPalindrome(string s) {
		if (s.size() <= 1) {
			return s;
		}
		string longest;
		for (int i = 0; i < s.size() - 1; i++) {    //分子串长为奇数和偶数两种情况，从最简单的情况出发
			if (longest.size() < findPalindrome(s, i, i).size()) {
				longest = findPalindrome(s, i, i);
			}
			if (longest.size() < findPalindrome(s, i, i + 1).size()) {
				longest = findPalindrome(s, i, i + 1);
			}
		}
		return longest;
	}
	//DP
	string longestPalindrome_DP(string s) {
		int n = s.size();
		if (n <= 1) return s;
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		int left = 0, len = 1;
		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
			if (i < n - 1 && s[i] == s[i + 1]) {
				dp[i][i + 1] = true;
				left = i;
				len = 2;
			}
		}
		for (int i = n - 3; i >= 0; i--) {
			for (int j = i + 2; j < n; j++) {
				if (s[i] == s[j] && dp[i + 1][j - 1]) {
					dp[i][j] = true;
					if (j - i + 1 > len) {
						len = j - i + 1;
						left = i;
					}
				}
			}
		}
		return s.substr(left, len);
	}
};

#if 0
int main() {
	string str("babab");
	Solution s;
	cout << s.longestPalindrome_DP(str) << endl;
	system("pause");
	return 0;
}
#endif