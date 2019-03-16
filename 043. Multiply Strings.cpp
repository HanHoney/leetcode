//43. Multiply Strings
//Medium

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") return "0";
		int len1 = num1.size();
		int len2 = num2.size();
		vector<int> ret(len1 + len2, 0);
		for (int i = len1 - 1; i >= 0; i--) {
			for (int j = len2 - 1; j >= 0; j--) {
				ret[i + j + 1] += (num1[i] - '0')*(num2[j] - '0');
			}
		}
		string res("");
		int carry = 0;
		for (int i = ret.size() - 1; i >= 0; i--) {
			int sum = ret[i] + carry;
			carry = sum / 10;
			ret[i] = sum % 10;
			res = (char)(ret[i] + '0') + res;
		}
		int idx = res.find_first_not_of('0');
		return res.substr(idx);
	}
};