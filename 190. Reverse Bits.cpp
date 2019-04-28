//190. Reverse Bits
//Easy

#include <iostream>
using namespace std;

class Solution {
public:

	//typedef unsigned int uint32_t;

	uint32_t reverseBits(uint32_t n) {
		uint32_t ret = 0;
		for (int i = 0; i < 32; ++i) {
			ret = (ret << 1) + (n >> i & 1);
		}
		return ret;
	}
};