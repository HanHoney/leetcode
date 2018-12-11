// 20. Valid Parentheses
// Easy

#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:

	/*******
	bool isValid1(string s) {
		int n = s.size();
		if (n % 2 != 0) return false;    //单数个符号
		stack<char> st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i]=='('||s[i]=='['||s[i]=='{') {
				st.push(s[i]);
			}
			else {
				if (st.empty()) return false;     //【注】保证stack中有元素
				char tmp = st.top();
				if ((tmp == '('&&s[i] == ')') || (tmp == '['&&s[i] == ']') || (tmp == '{'&&s[i] == '}')) {
					st.pop();
					continue;
				}
				else {
					return false;
				}
			}
		}
		return st.empty();
	}
	****************/

	bool isValid(string s) {
		int n = s.size();
		if (n % 2 == 1) return false;
		stack<char> st;
		unordered_map<char, char> m = { {')','('},{']','['},{'}','{'} };
		for (auto c : s) {
			if (m.find(c) != m.end()) {
				if (st.empty()||st.top()!=m[c]) return false;
				else st.pop();
			}
			else st.push(c);
		}
		return st.empty();
	}
};