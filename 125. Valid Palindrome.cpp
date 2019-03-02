//125. Valid Palindrome
//Easy

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int l = 0, r = s.size() - 1;
		while (l<r) {
			if (!isalnum(s[l])) l++;
			else if (!isalnum(s[r])) r--;
			else if (tolower(s[l++]) != tolower(s[r--])) {
				return false;
			}
		}
		return true;
	}
};

#if 0
int main() {
	string s1("A man, a plan, a canal: Panama");
	string s2("race a car");
	Solution s;
	cout << s.isPalindrome(s1) << endl;
	cout << s.isPalindrome(s2) << endl;
	system("pause");
	return 0;
}
#endif