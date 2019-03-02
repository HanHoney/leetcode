//131. Palindrome Partitioning
//Medium
//DFS

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> ret;
		if (s.empty()) return ret;
		vector<string> path;
		dfs(ret, path, s, 0);
		return ret;
	}
	void dfs(vector<vector<string>>& ret, vector<string>& path, string s, int index) {
		if (index == s.size()) {
			ret.push_back(path);
			return;
		}
		for (int i = index; i<s.size(); i++) {
			if (isPalindrome(s, index, i)) {
				path.push_back(s.substr(index, i - index + 1));
				dfs(ret, path, s, i + 1);
				path.pop_back();
			}
		}
	}
	bool isPalindrome(string s, int start, int end) {
		while (start<end) {
			if (s[start++] != s[end--]) {
				return false;
			}
		}
		return true;
	}
};