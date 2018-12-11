//70. Climbing Stairs
//Easy
//斐波那契数列
//避免重复计算超时，用数组保存结果而非递归

#include <vector>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {   //最大n为44，否则溢出
		vector<int> res(n + 1, 1);
		for (int i = 2; i <= n; i++) {
			res[i] = res[i - 2] + res[i - 1];
		}
		return res[n];
	}
};