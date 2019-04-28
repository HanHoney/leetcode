//784. Letter Case Permutation
//Easy

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> letterCasePermutation(string S) {
		vector<string> ret;
		if (S.empty()) return ret;
		dfs(ret, S, 0);
		return ret;
	}
	void dfs(vector<string>& ret, string str, int index) {
		if (index == str.size()) {
			ret.emplace_back(str);
			return;
		}
		dfs(ret, str, index + 1);
		if (str[index] >= 'a'&&str[index] <= 'z') {
			str[index] = str[index] - 'a' + 'A';
			dfs(ret, str, index + 1);
		}
		else if (str[index] >= 'A'&&str[index] <= 'Z') {
			str[index] = str[index] - 'A' + 'a';
			dfs(ret, str, index + 1);
		}
	}
};