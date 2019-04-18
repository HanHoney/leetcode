//887. Super Egg Drop
//Hard

//DP
//dp[k][m] = dp[k-1][m-1] (破了，往低层走)+ dp[k][m-1] (没破，往高层走) +1(当前层);	
//k个鸡蛋 m次试验 能测试到的最高楼层
//dp[k][0] = dp[0][m] = 0;
//成功测试的意思是：最高在第f层不会破掉，f的值在0到dp[k][m]之间，不论具体的f是多少，都可以用k个鸡蛋至多m次试验得到这个f的值。
//第m次的总楼层数由第m-1次决定。在更新dp[k]时需要上一轮的dp[k-1]和dp[k]，所以k是从大往小递减遍历。
//TC:O(KN)	SC:O(K)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int superEggDrop(int K, int N) {
		if (K == 1) return N;
		vector<int> dp(K + 1, 0);
		int m = 0;
		while (dp[K] < N) {
			++m;
			for (int i = K; i > 0; --i) {
				dp[i] += dp[i - 1] + 1;
			}
		}
		return m;
	}
};