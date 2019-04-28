//7. Reverse Integer

#include <iostream>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		bool negative = x < 0;
		long long llx = x;
		llx = abs(llx);
		long long ret = 0;
		while (llx) {
			ret = ret * 10 + llx % 10;
			llx /= 10;
		}
		if (negative) {
			ret = -ret;
		}
		if (ret > INT_MAX || ret < INT_MIN) return 0;
		return ret;
	}
};

#if 0
int main() {
	int x;
	Solution s;
	cout << INT_MAX <<endl;
	cout << INT_MIN << endl;
	cout << endl;
	while (cin >> x) {
		cout << s.reverse(x) << endl;
	}
}
#endif