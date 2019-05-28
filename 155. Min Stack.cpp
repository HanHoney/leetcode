//155. Min Stack
//Easy

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
	stack<int> s1;
	stack<int> s2;		//Î¬³ÖÒ»¸öµÝ¼õÕ»
public:
	void push(int x) {
		s1.push(x);
		if (s2.empty() || x <= s2.top()) s2.push(x);
	}
	void pop() {
		if (s1.top() == s2.top()) s2.pop();
		s1.pop();
	}
	int top() {
		return s1.top();
	}
	int getMin() {
		return s2.top();
	}
};
//
//int main() {
//	MinStack ms;
//	ms.push(-2);
//	ms.push(0);
//	ms.push(-3);
//	cout << ms.getMin() << endl;
//	ms.pop();
//	cout << ms.top() << endl;
//	cout << ms.getMin() << endl;
//	system("pause");
//	return 0;
//}