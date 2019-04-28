//326. Power of Three
//Easy

#include <iostream>
#include <math.h>
using namespace std;

class Solution {

	int maxPower(int base) {
		int ret = base;
		while (ret <= INT_MAX / base) {
			ret *= base;
		}
		return ret;
	}

public:
	bool isPowerOfThree(int n) {
		if (n <= 0) return false;	//note this
		while (n % 3 == 0) {
			n /= 3;
		}
		return n == 1;
	}

	bool isPowerOfThree_1(int n) {
		if (n <= 0) return false;
		int d = log10(n) / log10(3);	//ÓÃlog()ÓÐÎó²î
		return pow(3, d) == n;
	}

	bool isPowerOfThree_2(int n) {
		return n > 0 && maxPower(3) % n == 0;
	}
};