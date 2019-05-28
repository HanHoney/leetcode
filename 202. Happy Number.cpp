//202. Happy Number
//Easy

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		int curr = n;
		int next;
		unordered_set<int> s;
		s.insert(n);
		while(true) {
			next = nextNum(curr);
			if (next == 1) return true;
			if (s.find(next) != s.end()) return false;
			s.insert(next);
			curr = next;
		} 
	}
private:
	static int nextNum(int n) {
		int next = 0;
		while (n) {
			next += (n % 10)*(n % 10);
			n /= 10;
		}
		return next;
	}
};
//
//int main() {
//	Solution s;
//	int n;
//	while (cin >> n) {
//		cout << s.isHappy(n) << endl;
//	}
//	system("pause");
//	return 0;
//}