//470. Implement Rand10() Using Rand7()
//Medium

// The rand7() API is already defined for you.

#include <iostream>
#include <math.h>
using namespace std;

int rand7(){
	return rand() % 8;
}

class Solution {
public:
	int rand10() {
		int a;
		do {
			a = (rand7() - 1) + (rand7() - 1) * 7;	//{0,1,2,3,4,5,6} + {0,7,14,21,28,35,42}= 0~48 等概率
		} while (a >= 40);	//{0~39}等概率
		return a % 10 + 1;
	}
};