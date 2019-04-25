//140. Word Break II
//Hard
//相关题目：139. Word Break

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	//直接DFS => TLE
	//DP判断是否有解 + DFS给出具体解形式 => AC
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		vector<string> ret;
		if (s.size() == 0 || !helper(s, wordDict)) return ret;
		dfs(ret, "", s, wordDict);
		return ret;
	}
private:
	bool helper(string s, vector<string> wordDict) {
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
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
	void dfs(vector<string> &ret, string path, string s, vector<string> wordDict) {
		if (s == "") {
			path.pop_back();
			ret.emplace_back(path);
			return;
		}
		for (int i = 0; i < s.size(); ++i) {
			if (find(wordDict.begin(), wordDict.end(), s.substr(0, i + 1)) != wordDict.end()) {
				string tmp = path;
				path = path + s.substr(0, i + 1) + " ";
				dfs(ret, path, s.substr(i + 1), wordDict);
				path = tmp;
			}
		}
	}
};