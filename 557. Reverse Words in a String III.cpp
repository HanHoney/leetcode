//557. Reverse Words in a String III
//Easy

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		int left = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == ' ') {
				reverseWord(s, left, i - 1);
				left = i + 1;
			}
		}
		reverseWord(s, left, s.size() - 1);
		return s;
	}
	void reverseWord(string& s, int left, int right) {
		while (left < right) {
			swap(s[left++], s[right--]);
		}
	}
};