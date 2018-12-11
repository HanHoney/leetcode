//50. Pow(x, n)
//Medium
//����

#include <iostream>
#include <vector>
using namespace std;
class Solution {
	double myPow(double x, int n) {
		if (x == 1 || n == 0) return 1;
		double tmp = myPow(x, n / 2);
		if (n % 2 == 0) return tmp * tmp;
		else if (n > 0) return tmp * tmp * x;
		else return tmp * tmp / x;         //��������2�������Ǹ���
	}
};

//
//int main() {
//	cout << 3 / -2 << " " << 3 % -2 << endl;   //-1 1
//	cout << -3 / 2 << " " << -3 % 2 << endl;   //-1 -1
//	cout << -3 / -2 << " " << -3 % -2 << endl;   //1 -1
//	system("pause");
//	return 0;
//}
