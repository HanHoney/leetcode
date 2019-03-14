//771. Jewels and Stones
//Easy
//hash table

#include <iostream>
using namespace std;

class Solution {
public:
	int numJewelsInStones(string J, string S) {
		if (J.empty() || S.empty()) return 0;
		int ret = 0;
		bool lower[26] = { false };
		bool upper[26] = { false };
		for (int i = 0; i < J.size(); i++) {
			char ch = J[i];
			if (ch >= 'a'&&ch <= 'z') {
				lower[ch - 'a'] = true;
			}
			else if (ch >= 'A'&&ch <= 'Z') {
				upper[ch - 'A'] = true;
			}
		}
		for (int i = 0; i < S.size(); i++) {
			char ch = S[i];
			if (ch >= 'a'&&ch <= 'z') {
				if (lower[ch - 'a']) {
					ret++;
				}
			}
			else if (ch >= 'A'&&ch <= 'Z') {
				if (upper[ch - 'A']) {
					ret++;
				}
			}
		}
		return ret;
	}
};