// 9. Palindrome Number
// �������һ����ֻ��һ���Ƚϡ�

#include <iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
		int z = x;
		int y = 0;
		while (z) {
			y = y * 10 + z % 10;
			z /= 10;
		}
		return x == y;
	}
};

//int main() {
//	Solution s;
//	cout << s.isPalindrome(-121) << endl;
//	cout << s.isPalindrome(0) << endl;
//	cout << s.isPalindrome(121) << endl;
//	cout << s.isPalindrome(10) << endl;
//	system("pause");
//}
