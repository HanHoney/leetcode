//383. Ransom Note
//Easy

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		if (magazine.size() < ransomNote.size()) return false;
		int ma[26] = { 0 };
		for (char c : magazine) {
			ma[c - 'a']++;
		}
		for (char c : ransomNote) {
			ma[c - 'a']--;
			if (ma[c - 'a'] < 0) return false;
		}
		return true;
	}
};