//17. Letter Combinations of a Phone Number
//¢ÙµÝ¹é£¨DFS£©
//¢Úµü´ú

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		if (digits.empty())
			return ret;
		const vector<string> keyboard = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		ret.push_back("");
		for (int i = 0; i < digits.size(); i++) {
			string s = keyboard[digits[i] - '0'];
			ret = DFS(ret, s);
		}
		return ret;
	}
	vector<string> DFS(vector<string> res, string s) {
		vector<string> ret;
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < s.size(); j++) {
				ret.push_back(res[i] + s[j]);
			}
		}
		return ret;
	}
};

