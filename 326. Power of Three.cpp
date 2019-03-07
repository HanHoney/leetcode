//326. Power of Three
//Easy

#include <iostream>
using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n <= 0) return false;	//note this
		while (n % 3 == 0) {
			n /= 3;
		}
		return n == 1;
	}
};