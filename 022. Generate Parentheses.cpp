//22. Generate Parentheses
//Medium
//解的个数是卡特兰数。生成函数，所有位置满足规则【左括号数大于等于右括号数】即可打印括号。
//left：未打印的左括号数  right：未打印的右括号数

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		string path = "";
		dfs(ret, path, n, n);
		return ret;
	}
	void dfs(vector<string>& ret, string path, int left, int right) {
		if (left < 0 || left > right) return;
		if (left == 0 && right == 0) {
			ret.emplace_back(path);
		}
		path.push_back('(');
		dfs(ret, path, left - 1, right);
		path.back() = ')';
		dfs(ret, path, left, right - 1);
	}
};