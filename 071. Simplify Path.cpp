//71. Simplify Path
//Medium

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	//stack
	string simplifyPath(string path) {
		string ret = "";
		stack<string> stk;
		int left = -1;
		path.push_back('/');    //不用再特殊考虑最后一个字符串
		for (int i = 0; i < path.size(); ++i) {
			if (path[i] == '/') {
				if (i - left > 1) {
					string tmp = path.substr(left + 1, i - left - 1);
					if (tmp == ".." && !stk.empty()) {
						stk.pop();
					}
					else if (tmp != "."&&tmp != "..") {
						stk.push(tmp);
					}
				}
				left = i;
			}
		}
		while (!stk.empty()) {
			ret = "/" + stk.top() + ret;
			stk.pop();
		}
		if (ret.size() == 0) {
			ret = "/";
		}
		return ret;
	}
};
