//58. Length of Last Word
//Easy

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.empty()) return 0;
		int end = s.size() - 1;
		int ret = 0;
		while (end >= 0 && s[end] == ' ') end--;
		while (end >= 0 && s[end--] != ' ') {
			ret++;
		}
		return ret;
	}
};