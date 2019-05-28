//313. Super Ugly Number
//Medium

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> ret(n, INT_MAX);
		ret[0] = 1;
		vector<int> idx(primes.size(), 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < primes.size(); j++) {
				ret[i] = min(ret[i], primes[j] * ret[idx[j]]);
			}
			for (int j = 0; j < primes.size(); j++) {	//防止相同元素出现
				if (primes[j] * ret[idx[j]] == ret[i]) {
					idx[j]++;
				}
			}
		}
		return ret[n - 1];
	}
};

//
//int main() {
//	vector<int> primes{ 2,7,13,19 };
//	int n;
//	Solution s;
//	while (cin >> n) {
//		cout << s.nthSuperUglyNumber(n, primes) << endl;
//	}
//	system("pause");
//	return 0;
//}