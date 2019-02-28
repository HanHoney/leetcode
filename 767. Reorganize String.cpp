//767. Reorganize String
//Medium
//Greedy
//必须先把个数最多的字符插入，再插入其他，否则个数最多的字符可能相邻

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reorganizeString(string S) {
		int map[26] = { 0 };
		int maxcnt = 0;
		char maxchar;
		for (char c : S) {
			map[c - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (map[i] > maxcnt) {
				maxcnt = map[i];
				maxchar = i + 'a';
			}
		}
		if (maxcnt * 2 > S.size() + 1) return "";
		int idx = 0;
		for (int i = 0; i < maxcnt; i++) {
			S[idx] = maxchar;
			idx += 2;
		}
		for (int i = 0; i < 26; i++) {
			if (i + 'a' == maxchar) continue;
			for (int j = 0; j < map[i]; j++) {
				if (idx >= S.size()) {
					idx = 1;
				}
				S[idx] = i + 'a';
				idx += 2;
			}
		}
		return S;
	}
};

#if 0
int main() {
	string str("aaabbbbbcc");
	Solution s;
	cout << s.reorganizeString(str) << endl;
	system("pause");
	return 0;
}
#endif