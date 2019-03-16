//151. Reverse Words in a String
//Medium

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		int idx = 0;
		for (int i = 0; i<s.size(); i++) {
			if (s[i] != ' ' || (i > 0 && s[i - 1] != ' ')) {
				s[idx++] = s[i];
			}
		}
		if (s[idx - 1] == ' ') idx--;
		s = s.substr(0, idx);
		reverse(s, 0, s.size() - 1);
		int left = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				reverse(s, left, i - 1);
				left = i + 1;
			}
		}
		reverse(s, left, s.size() - 1);
		return s;
	}
	void reverse(string& s, int start, int end) {
		while (start < end) {
			swap(s[start++], s[end--]);
		}
	}
};