//14. Longest Common Prefix

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ret;
		if (strs.size() <= 0) {
			return ret;
		}
		for (int i = 0; i < strs[0].size(); i++) {
			string tmp = strs[0].substr(0, i + 1);    //È¡³ö×Ó´®
			bool isMatched = true;
			for (int j = 1; j < strs.size(); j++) {
				if (strs[j].substr(0, i + 1) != tmp || strs[j].size() < i + 1) {
					isMatched = false;
					break;
				}
			}
			if (isMatched) {
				ret = tmp;
			}
		}
		return ret;
	}
};