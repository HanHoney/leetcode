//13. Roman to Integer

#include <iostream>
#include <map>
using namespace std;

class Soltuion {
public:
	int romanToInt(string s) {
		map<char, int> romanInt = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
		int res = 0;
		for (int i = 0; i < s.length(); i++) {
			if (romanInt[s[i]] < romanInt[s[i + 1]] && i < s.length() - 1) {    //小的数字在左，减去
				res -= romanInt[s[i]];
			}
			else
				res += romanInt[s[i]];
		}
		return res;
	}

};