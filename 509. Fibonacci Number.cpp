//509. Fibonacci Number
//Easy

#include <iostream>
using namespace std;

class Solution {
public:
	int fib(int N) {
		if (N == 0) return 0;
		if (N == 1) return 1;
		int f0 = 0, f1 = 1;
		for (int i = 2; i <= N; i++) {
			int t = f0 + f1;
			f0 = f1;
			f1 = t;
		}
		return f1;
	}   
};