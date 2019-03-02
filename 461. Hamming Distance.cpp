//461. Hamming Distance
//Easy

#include <iostream>
using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		int t = x ^ y;
		int ret = 0;
		while (t) {
			t = t & (t - 1);
			ret++;
		}
		return ret;
	}
};