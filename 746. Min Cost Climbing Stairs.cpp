//746. Min Cost Climbing Stairs
//Easy
//注意题意理解~cost数组是每个台阶行动的消耗，若size为n，则总台阶数是n+1。。

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		vector<int> res(n + 1, 0);
		for (int i = 2; i <= n; i++) {
			res[i] = min(res[i - 2] + cost[i - 2], res[i - 1] + cost[i - 1]);
		}
		return res[n];
	}
};