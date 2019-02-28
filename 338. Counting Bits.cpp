//338. Counting Bits
//Medium
//i&(i-1)可以去掉二进制中最后一个1

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		if (num < 0) return vector<int>{};
		vector<int> ret(num + 1, 0);
		for (int i = 1; i <= num; i++) {
			ret[i] = ret[i&(i - 1)] + 1;
		}
		return ret;
	}
};

