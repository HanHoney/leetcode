//8. String to Integer(atoi)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		if (str.empty()) return 0;
		bool negative = false;
		int i = 0;
		while (i < str.size()) {
			if (str[i] != ' ') {
				break;
			}
			++i;
		}
		if (i == str.size()) return 0;
		if (str[i] == '-') {
			negative = true;
			++i;
		}
		else if (str[i] == '+') {
			++i;
		}
		if (!isdigit(str[i])) {
			return 0;
		}
		long long ret = 0;
		while (i < str.size() && isdigit(str[i])) {
			ret = 10 * ret + str[i] - '0';
			++i;
			if (ret / 10 > INT_MAX) {
				break;
			}
		}
		if (negative) {
			ret = -ret;
		}
		if (ret < INT_MIN) {
			return INT_MIN;
		}
		if (ret > INT_MAX) {
			return INT_MAX;
		}
		return ret;
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
