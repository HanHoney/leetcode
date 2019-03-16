//93. Restore IP Addresses
//Medium
//DFS

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> ret;
		vector<string> path;
		dfs(s, 0, path, ret);
		return ret;
	}
	void dfs(string s, int idx, vector<string>& path, vector<string>& ret) {
		if (idx == s.size() && path.size() == 4) {
			string ip(path[0]);
			for (int i = 1; i < 4; i++) {
				ip = ip + "." + path[i];
			}
			ret.push_back(ip);
			return;
		}
		else if (idx == s.size() || path.size() == 4) return;
		int sum = 0;
		for (int i = 0; i < 3 && idx + i < s.size(); i++) {		//注意idx+i<s.size()
			sum = sum * 10 + (s[idx + i] - '0');
			if (sum <= 255) {
				path.push_back(s.substr(idx, i + 1));
				dfs(s, idx + i + 1, path, ret);
				path.pop_back();
			}
			if (sum == 0) break;								//若第一位是0，则无需再尝试其他划分方式
		}
	}
};