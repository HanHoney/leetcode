//150. Evaluate Reverse Polish Notation
//Medium
//ÇóÄæ²¨À¼Ê½
//stack

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for (string t : tokens) {
			if (t == "+" || t == "-" || t == "*" || t == "/") {
				int x = s.top();
				s.pop();
				int y = s.top();
				s.pop();
				if (t == "+") {
					s.push(y + x);
				}
				if (t == "-") {
					s.push(y - x);
				}
				if (t == "*") {
					s.push(y * x);
				}
				if (t == "/") {
					s.push(y / x);
				}
			}
			else {
				s.push(stoi(t));
			}
		}
		return s.top();
	}
};

#if 0
int main(int argc,char* argv[]) {
	vector<string> tokens{ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	Solution s;
	cout << s.evalRPN(tokens) << endl;
	system("pause");
	return 0;
}
#endif
