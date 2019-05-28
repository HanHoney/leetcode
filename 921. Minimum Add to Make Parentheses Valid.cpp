//921. Minimum Add to Make Parentheses Valid
//Medium


#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int minAddToMakeValid(string S) {
		stack<char> stk;
		for (char c : S) {
			if (c == ')' && !stk.empty() && stk.top() == '(') {
				stk.pop();
			}
			else {
				stk.push(c);
			}
		}
		return stk.size();
	}
};