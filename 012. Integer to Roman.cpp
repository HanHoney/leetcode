//12. Integer to Roman
//扩充原始的表，直接匹配

#include <iostream>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string romans[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
		int integer[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		string ret;
		for (int i = 0; num != 0; i++) {
			while (num >= integer[i]) {
				num -= integer[i];
				ret += romans[i];
			}
		}
		return ret;
	}
};