// 29. Divide Two Integers
// Medium
// 注意溢出问题，用无符号整型处理
// 注意超时问题

#include <iostream>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) return 0;
		if (dividend == INT_MIN && divisor == -1) return INT_MAX;   //结果溢出
		if (divisor == INT_MIN) return dividend == INT_MIN;         //除数为最大负数，其绝对值溢出
		int ret = 0;
		bool neg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor>0);
		divisor = abs(divisor);
		if (dividend == INT_MIN) {    //被除数为最大负数，其绝对值溢出
			dividend += divisor;
			ret++;
		}
		dividend = abs(dividend);

		//正整数做除法【位运算】
		while (dividend >= divisor) {
			int a = divisor;
			int t = 1;
			while ((a << 1) > 0 && (a << 1) < dividend) {   //除数一直左移倍增，结果同样保持倍增，将被除数表示为除数不同倍数的和
				a <<= 1;
				t <<= 1;
			}
			ret += t;
			dividend -= a;
		}
		return neg ? -ret : ret;
	}
};
