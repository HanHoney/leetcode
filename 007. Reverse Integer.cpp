//7. Reverse Integer

#include <iostream>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		int ret = 0;
		while (x) {
			int tmp = x % 10;
			if (ret > INT_MAX/10 || ret < INT_MIN/10) {   //-2^31~2^31-1
				return 0;
			}
			ret = ret * 10 + tmp;
			x /= 10;
		}
		return ret;
	}
};
//int main() {
//	int x;
//	Solution s;
//	cout << INT_MAX <<endl;
//	cout << INT_MIN << endl;
//	cout << endl;
//	while (cin >> x) {
//		cout << s.reverse(x) << endl;
//	}
//}