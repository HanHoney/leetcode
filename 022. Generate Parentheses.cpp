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
		if (n == 0) return vector<string>(1,"");
		if (n == 1) return vector<string>(1, "()");
		vector<string> ret;
		string s;
		generate(s, n, n, ret);
		return ret;
	}
	void generate(string str,int left,int right,vector<string> &res) {  //无法再添加括号时，不再调用generate，递归出口。
		if (left == 0 && right == 0) {   
			res.push_back(str);
		}
		if (left > 0) {  //加左括号
			generate(str + "(", left - 1, right, res);
		}
		if (right > 0 && right > left) {   //加右括号
			generate(str + ")", left, right - 1, res);
		}
		return;   //可省略，写出来逻辑更清晰~
	}
};