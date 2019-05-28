//263. Ugly Number
//Easy
/*
Note:
	1. 1 is typically treated as an ugly number.
	2. Input is within the 32-bit signed integer range: [−2^31, 2^31 − 1].
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isUgly(int num) {
		if (num <= 0) return false;
		while (num % 2 == 0) num /= 2;
		while (num % 3 == 0) num /= 3;
		while (num % 5 == 0) num /= 5;
		return num == 1;
	}
};

//
//int main() {
//	Solution s;
//	cout << s.isUgly(1) << endl;
//	cout << s.isUgly(6) << endl;
//	cout << s.isUgly(8) << endl;
//	cout << s.isUgly(14) << endl;
//	system("pause");
//	return 0;
//}