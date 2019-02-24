//441. Arranging Coins
//Easy

#include <math.h>

class Solution {
public:
	int arrangeCoins(int n) {
		return sqrt((long long)2 * n + 0.25) - 0.5;
	}
};