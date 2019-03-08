//227. Basic Calculator II
//Medium

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		stack<int> stk;
		int ret = 0;
		int tmp = 0;
		char sign = '+';
		for (int i = 0; i<s.size(); i++) {
			if (isdigit(s[i])) {
				tmp = s[i] - '0' + tmp * 10;	//注意顺序 tmp*10+s[i]可能会溢出
			}
			if (i == s.size() - 1 || (!isdigit(s[i]) && s[i] != ' ')) {

				if (sign == '+') {
					stk.push(tmp);
				}
				else if (sign == '-') {
					stk.push(-tmp);
				}
				else {
					int num;
					if (sign == '*') {
						num = stk.top()*tmp;
					}
					else {
						num = stk.top() / tmp;
					}
					stk.pop();
					stk.push(num);
				}
				sign = s[i];
				tmp = 0;
			}
		}
		while (!stk.empty()) {
			ret += stk.top();
			stk.pop();
		}
		return ret;
	}
};