// 29. Divide Two Integers
// Medium
// ע��������⣬���޷������ʹ���
// ע�ⳬʱ����

#include <iostream>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) return 0;
		if (dividend == INT_MIN && divisor == -1) return INT_MAX;   //������
		if (divisor == INT_MIN) return dividend == INT_MIN;         //����Ϊ������������ֵ���
		int ret = 0;
		bool neg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor>0);
		divisor = abs(divisor);
		if (dividend == INT_MIN) {    //������Ϊ������������ֵ���
			dividend += divisor;
			ret++;
		}
		dividend = abs(dividend);

		//��������������λ���㡿
		while (dividend >= divisor) {
			int a = divisor;
			int t = 1;
			while ((a << 1) > 0 && (a << 1) < dividend) {   //����һֱ���Ʊ��������ͬ�����ֱ���������������ʾΪ������ͬ�����ĺ�
				a <<= 1;
				t <<= 1;
			}
			ret += t;
			dividend -= a;
		}
		return neg ? -ret : ret;
	}
};
