//264. Ugly Number II
//Medium
//DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> res;
		res.push_back(1);
		int i = 0, j = 0, k = 0;
		while (res.size() < n) {
			int next = min(min(res[i] * 2, res[j] * 3), res[k] * 5);
			res.push_back(next);
			if (next == res[i] * 2) i++;	//可能有重复的元素，不能用else if
			if (next == res[j] * 3) j++;
			if (next == res[k] * 5) k++;
		}
		return res.back();
	}
};

int main() {
	Solution s;
	int n;
	while (cin >> n) {
		cout << s.nthUglyNumber(n) << endl;
	}
	return 0;
}