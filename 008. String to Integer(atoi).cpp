//8. String to Integer(atoi)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int len = str.length();
		bool neg = false;
		bool flag = false;
		int ret = 0;
		if (len == 0) {
			return 0;
		}
		int i = 0;
		for (; i < len; i++) {
			if (str[i] != ' ') {
				break;
			}
		}
		if (str[i] == '-') {
			neg = true;
			i++;
		}
		else if (str[i] == '+') {     //注意此处的逻辑。正负号连续出现非法，只读入一个操作符。
			i++;
		}
		if (str[i]<'0'&&str[i]>'9') {
			return 0;
		}
		while (str[i] >= '0'&&str[i] <= '9'&&i < len) {
			int digit = str[i++] - '0';
			if (neg) {
				if (-ret < (INT_MIN + digit) / 10) {    //判断溢出情况
					return INT_MIN;
				}
			}
			else {
				if (ret > (INT_MAX - digit) / 10) {
					return INT_MAX;
				}
			}
			ret = ret * 10 + digit;
		}
		return neg ? -ret : ret;
	}
};
/*
int main() {
	Solution s;
	cout << s.myAtoi(" +123") << endl;
	cout << s.myAtoi("   -123") << endl;
	cout << s.myAtoi("12300000000") << endl;
	cout << s.myAtoi("-12300000000") << endl;
	cout << s.myAtoi("123a") << endl;
	cout << s.myAtoi("a123") << endl;
	cout << s.myAtoi("123") << endl;
	cout << s.myAtoi("+-1") << endl;
	system("pause");
}
*/
