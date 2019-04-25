//139. Word Break
//Medium
//DP
//��ע��vector��û��find��������algorithmͷ�ļ���

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	// DFS => TLE
	// DP  => AC
	bool wordBreak(string s, vector<string>& wordDict) {
		if (s.empty() || wordDict.empty()) return false;
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		//dp[i] s[0..i-1]�Ƿ���Ա����
		//dp[i]= dp[j] && s[j..i-1]��wordDict,j��[0,i-1] ��i�����ȡ��
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[s.size()];
	}
};

#if 0
int main() {
	vector<string> wordDict1{ "leet","code" };
	vector<string> wordDict2{ "apple","pen" };
	vector<string> wordDict3{ "cats","dog","sand","and","cat" };
	string s1("leetcode");
	string s2("applepenapple");
	string s3("catsandog");
	Solution s;
	cout << s.wordBreak(s1, wordDict1) << endl;
	cout << s.wordBreak(s2, wordDict2) << endl;
	cout << s.wordBreak(s3, wordDict3) << endl;
	system("pause");
	return 0;
}
#endif