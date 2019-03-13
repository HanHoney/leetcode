//67. Add Binary
//Easy

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int i = a.size() - 1;
		int j = b.size() - 1;
		int carry = 0;
		string ret("");
		if (a.empty() || (a.size() == 1 && a[0] == '0')) {
			return b;
		}
		if (b.empty() || (b.size() == 1 && b[0] == '0')) {
			return a;
		}
		while (i >= 0 || j >= 0 || carry > 0) {
			int x = i >= 0 ? (a[i--] - '0') : 0;
			int y = j >= 0 ? (b[j--] - '0') : 0;
			int sum = x + y + carry;
			ret = (char)(sum % 2 + '0') + ret;
			carry = sum / 2;
		}
		return ret;
	}
};