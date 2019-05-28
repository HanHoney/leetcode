//844. Backspace String Compare
//Easy

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		stack<char> s1;
		stack<char> s2;
		for (auto ch : S) {
			if (ch == '#') {
				if (!s1.empty()) s1.pop();
			}
			else s1.push(ch);
		}
		for (auto ch : T) {
			if (ch == '#') {
				if (!s2.empty()) s2.pop();
			}
			else s2.push(ch);
		}
		if (s1.size() != s2.size()) return false;
		while (!s1.empty()) {
			if (s1.top() != s2.top()) return false;
			s1.pop();
			s2.pop();
		}
		return true;
	}
};