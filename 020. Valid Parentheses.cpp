// 20. Valid Parentheses
// Easy

#include <vector>
#include <string>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:

	bool isValid(string s) {
		if (s.empty()) return true;
		if (s.size() & 1) return false;
		map<char, char> map = { {')','('},{']','['},{'}','{'} };
		stack<char> stk;
		for (char ch : s) {
			if (ch == '(' || ch == '[' || ch == '{') {
				stk.push(ch);
			}
			else {
				if (stk.empty() || stk.top() != map[ch]) {
					return false;
				}
				stk.pop();
			}
		}
		return stk.empty();
	}
};