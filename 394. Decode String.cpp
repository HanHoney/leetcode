//394. Decode String
//Medium

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	string decodeString(string s) {
		stack<string> strs;
		stack<int> cnts;
		string ret("");
		int cnt = 0;
		for (char c : s) {
			if (isdigit(c)) {
				cnt = cnt * 10 + c - '0';
			}
			else if (isalpha(c)) {
				ret += c;
			}
			else if (c == '[') {
				strs.push(ret);
				cnts.push(cnt);
				ret = "";
				cnt = 0;
			}
			else if (c == ']') {
				string tmp;
				for (int i = 0; i < cnts.top(); ++i) {
					tmp += ret;
				}
				ret = strs.top() + tmp;
				strs.pop();
				cnts.pop();
			}
		}
		return ret;
	}
};

#if 0
int main() {
	string s1("3[a]2[bc]");
	string s2("3[a2[c]]");
	string s3("2[abc]3[cd]ef");
	string s4("ab3[cde]f2[g]h");
	Solution s;
	cout << s1 << ',' << s.decodeString(s1) << endl;
	cout << s2 << ',' << s.decodeString(s2) << endl;
	cout << s3 << ',' << s.decodeString(s3) << endl;
	cout << s4 << ',' << s.decodeString(s4) << endl;
	system("pause");
	return 0;
}
#endif